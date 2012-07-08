#include "analog.h"

#if 0
DWORD getAdc(BYTE port)
{
  AD1CON1bits.ADON = 0;
  AD1CHS = (DWORD)port << 16;
  AD1CON1bits.ADON = 1;
  AD1CON1bits.SAMP = 1;
  delayUs(10);
  AD1CON1bits.SAMP = 0;
  while(!AD1CON1bits.DONE);
  return ADC1BUF0;
}
#endif

void resetAnalogFlag(BYTE port)
{
	analogSendFlag[port] = FALSE;
}

BOOL getAnalogFlag(BYTE port)
{
	return analogSendFlag[port];
}

BYTE getAnalogByte(BYTE port, BYTE type)
{
  float fader;
  BYTE vol;

  switch(type)
  {
    case TYPE_MIDI_FADER:
    	fader = (float)(currentAnalog[port] >> 3) * 1.008;
       	if(fader < 2.0)
          fader = 0.0;
       	else if(fader > 127.0)
          fader = 127.0;
       	vol = (BYTE)fader;
    	break;
    case TYPE_MIDI_VOLUME:
    	vol = (BYTE)(127 - (currentAnalog[port] >> 3));
       	if(vol > 60 && vol < 66)
          vol = 63;
    	break;
  }
	return vol;
}

WORD getAnalogWord(BYTE port, BYTE type)
{
  float fader;
  WORD vol;

  switch(type)
  {
    case TYPE_LONG_FADER:
      fader = (float)(currentAnalog[port]) * 1.008;
      if(fader < 8.0)
        fader = 0.0;
      else if(fader > 1024.0)
        fader = 1024.0;
      vol = (WORD)fader;
      break;
    case TYPE_LONG_VOLUME:
      vol = (WORD)(1024 - currentAnalog[port]);
      if(vol > 506 && vol < 518)
        vol = 512;
      break;
  }
  return vol;
}

void analogInHandle(BYTE port, DWORD value)
{
	BYTE i;

  analog[port][count[port]] = value;
  count[port]++;

  if(count[port] == FLTR_ADC_CNT)
  {
    currentAnalog[port] = 0;
    for(i = 0; i < FLTR_ADC_CNT; i++)
      currentAnalog[port] += analog[port][i];
    currentAnalog[port] /= (DWORD)FLTR_ADC_CNT;
    if(abs(currentAnalog[port] - prevAnalog[port]) > 4)
    {
      prevAnalog[port] = currentAnalog[port];
      analogSendFlag[port] = TRUE;
    }
    count[port] = 0;
  }
}