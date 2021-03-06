/*
 * Copylight (C) 2012, Shunichi Yamamoto, tkrworks.net
 *
 * This file is part of PICrouter.
 *
 * PICrouter is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option ) any later version.
 *
 * PICrouter is distributed in the hope that it will be useful,
 * but WITHIOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PICrouter. if not, see <http:/www.gnu.org/licenses/>.
 *
 * lcd.c,v.0.1.2 2013/09/06
 */

#define __LCD_C

//#include <string.h>
//#include "Compiler.h"
//#include "GenericTypeDefs.h"
//#include "HardwareProfile.h"
#include "lcd.h"
//#include "iosetting.h"

BYTE lcdText[CHARS_NUM * LINE_NUM + 1];

static BOOL initLcdFlag = FALSE;
static BYTE bit_mode = 0;
static char pin_rs[4]  = {0};
static char pin_rw[4]  = {0};
static char pin_e[4]   = {0};
static char pin_db0[4] = {0};
static char pin_db1[4] = {0};
static char pin_db2[4] = {0};
static char pin_db3[4] = {0};
static char pin_db4[4] = {0};
static char pin_db5[4] = {0};
static char pin_db6[4] = {0};
static char pin_db7[4] = {0};

/*******************************************************************************
  Function:
    void setLcdInitFlag(BOOL flag)

  Precondition:


  Summary:


  Description:


  Parameters:
    BOOL flag

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdInitFlag(BOOL flag)
{
    initLcdFlag = flag;
}

/*******************************************************************************
  Function:
    BOOL getLcdInitFlag(void)

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
BOOL getLcdInitFlag(void)
{
    return initLcdFlag;
}

/*******************************************************************************
  Function:
    void setLcdBitMode(BYTE num)

  Precondition:


  Summary:


  Description:


  Parameters:
    BYTE num

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdBitMode(BYTE num)
{
    bit_mode = num;
}

/*******************************************************************************
  Function:
    BYTE getLcdBitMode(void)

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
BYTE getLcdBitMode(void)
{
    return bit_mode;
}

/*******************************************************************************
  Function:
    void setLcdPortRsName(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortRsName(char* name)
{
    memset(pin_rs, 0, sizeof(pin_rs));
    strcpy(pin_rs, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortRsName()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortRsName()
{
    return pin_rs;
}

/*******************************************************************************
  Function:
    void setLcdPortRwName(char* name)

  Precondition:


  Summary:


  Description:
    None

  Parameters:
    char* name

  Return Values:


  Remarks:
    None
*******************************************************************************/
void setLcdPortRwName(char* name)
{
    memset(pin_rw, 0, sizeof(pin_rw));
    strcpy(pin_rw, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortRwName(void)

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortRwName(void)
{
    return pin_rw;
}

/*******************************************************************************
  Function:
    void setLcdPortEName(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortEName(char* name)
{
    memset(pin_e, 0, sizeof(pin_e));
    strcpy(pin_e, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortEName()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortEName()
{
    return pin_e;
}

/*******************************************************************************
  Function:
    void setLcdPortDb0Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb0Name(char* name)
{
    memset(pin_db0, 0, sizeof(pin_db0));
    strcpy(pin_db0, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb0Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb0Name()
{
    return pin_db0;
}

/*******************************************************************************
  Function:
    void setLcdPortDb1Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb1Name(char* name)
{
    memset(pin_db1, 0, sizeof(pin_db1));
    strcpy(pin_db1, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb1Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb1Name()
{
    return pin_db1;
}

/*******************************************************************************
  Function:
    void setLcdPortDb2Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb2Name(char* name)
{
    memset(pin_db2, 0, sizeof(pin_db2));
    strcpy(pin_db2, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb2Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb2Name()
{
    return pin_db2;
}

/*******************************************************************************
  Function:
    void setLcdPortDb3Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb3Name(char* name)
{
    memset(pin_db3, 0, sizeof(pin_db3));
    strcpy(pin_db3, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb3Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb3Name()
{
    return pin_db3;
}

/*******************************************************************************
  Function:
    void setLcdPortDb4Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb4Name(char* name)
{
    memset(pin_db4, 0, sizeof(pin_db4));
    strcpy(pin_db4, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb4Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb4Name()
{
    return pin_db4;
}

/*******************************************************************************
  Function:
    void setLcdPortDb5Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb5Name(char* name)
{
    memset(pin_db5, 0, sizeof(pin_db5));
    strcpy(pin_db5, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb5Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb5Name()
{
    return pin_db5;
}

/*******************************************************************************
  Function:
    void setLcdPortDb6Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb6Name(char* name)
{
    memset(pin_db6, 0, sizeof(pin_db6));
    strcpy(pin_db6, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb6Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb6Name()
{
    return pin_db6;
}

/*******************************************************************************
  Function:
    void setLcdPortDb7Name(char* name)

  Precondition:


  Summary:


  Description:


  Parameters:
    char* name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void setLcdPortDb7Name(char* name)
{
    memset(pin_db7, 0, sizeof(pin_db7));
    strcpy(pin_db7, name);
}

/*******************************************************************************
  Function:
    char* getLcdPortDb7Name()

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:


  Remarks:
    None
*******************************************************************************/
char* getLcdPortDb7Name()
{
    return pin_db7;
}

/*******************************************************************************
  Function:
    static void writeLcd(BYTE rs_state, BYTE data)

  Precondition:


  Summary:


  Description:


  Parameters:
    BYTE rs_state
    BYTE data

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
static void writeLcd(BYTE rs_state, BYTE data)
{
        if(bit_mode == 8)
        {
            setPortIOType(pin_db0, IO_OUT);
            setPortIOType(pin_db1, IO_OUT);
            setPortIOType(pin_db2, IO_OUT);
            setPortIOType(pin_db3, IO_OUT);
        }
        setPortIOType(pin_db4, IO_OUT);
        setPortIOType(pin_db5, IO_OUT);
        setPortIOType(pin_db6, IO_OUT);
        setPortIOType(pin_db7, IO_OUT);

        setPortIOType(pin_rs, IO_OUT);
        setPortIOType(pin_rw, IO_OUT);

        outputPort(pin_rw, LOW);
        outputPort(pin_rs, rs_state);

        if(bit_mode == 4)
        {
#if 0
            outputPort(pin_db4, ((data & 0x01) == 0x01));
            outputPort(pin_db5, ((data & 0x02) == 0x02));
            outputPort(pin_db6, ((data & 0x04) == 0x04));
            outputPort(pin_db7, ((data & 0x08) == 0x08));
#else
            outputPort(pin_db4, ((data & 0x10) == 0x10));
            outputPort(pin_db5, ((data & 0x20) == 0x20));
            outputPort(pin_db6, ((data & 0x40) == 0x40));
            outputPort(pin_db7, ((data & 0x80) == 0x80));
#endif
            Nop();
            Nop();
            outputPort(pin_e, HIGH);
            Nop();
            Nop();
            Nop();
            Nop();
            Nop();
            Nop();
            Nop();
            Nop();
            Nop();
            outputPort(pin_e, LOW);
        }

#if 0
        outputPort(pin_db0, ((data & 0x01) == 0x01));
        outputPort(pin_db1, ((data & 0x02) == 0x02));
        outputPort(pin_db2, ((data & 0x04) == 0x04));
        outputPort(pin_db3, ((data & 0x08) == 0x08));
#endif

#if 0
        if(bit_mode == 8)
        {
            outputPort(pin_db4, ((data & 0x10) == 0x10));
            outputPort(pin_db5, ((data & 0x20) == 0x20));
            outputPort(pin_db6, ((data & 0x40) == 0x40));
            outputPort(pin_db7, ((data & 0x80) == 0x80));
        }
#else
        outputPort(pin_db4, ((data & 0x01) == 0x01));
        outputPort(pin_db5, ((data & 0x02) == 0x02));
        outputPort(pin_db6, ((data & 0x04) == 0x04));
        outputPort(pin_db7, ((data & 0x08) == 0x08));
#endif
        Nop();
        Nop();
        outputPort(pin_e, HIGH);
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        Nop();
        outputPort(pin_e, LOW);

        if(bit_mode == 8)
        {
            setPortIOType(pin_db0, IO_IN);
            setPortIOType(pin_db1, IO_IN);
            setPortIOType(pin_db2, IO_IN);
            setPortIOType(pin_db3, IO_IN);
        }
        setPortIOType(pin_db4, IO_IN);
        setPortIOType(pin_db5, IO_IN);
        setPortIOType(pin_db6, IO_IN);
        setPortIOType(pin_db7, IO_IN);

        setPortIOType(pin_rs, IO_IN);
        setPortIOType(pin_rw, IO_IN);
}

/*******************************************************************************
  Function:
    void initLcd(BYTE bit_mode_num, char* rs_name, char* rw_name, char* e_name, char* db0_name, char* db1_name, char* db2_name, char* db3_name, char* db4_name, char* db5_name, char* db6_name, char* db7_name)

  Precondition:


  Summary:


  Description:


  Parameters:
    BYTE bit_mode_num
    char* rs_name
    char* rw_name
    char* e_name
    char* db0_name
    char* db1_name
    char* db2_name
    char* db3_name
    char* db4_name
    char* db5_name
    char* db6_name
    char* db7_name

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void initLcd(BYTE bit_mode_num, char* rs_name, char* rw_name, char* e_name, char* db0_name, char* db1_name, char* db2_name, char* db3_name, char* db4_name, char* db5_name, char* db6_name, char* db7_name)
{
	BYTE i;

        if(initLcdFlag)
            return;
        
        initLcdFlag = TRUE;

	memset(lcdText, ' ', sizeof(lcdText) - 1);
	lcdText[sizeof(lcdText) - 1] = 0;

        setLcdBitMode(bit_mode_num);
        setLcdPortRsName(rs_name);
        setLcdPortRwName(rw_name);
        setLcdPortEName(e_name);
        if(bit_mode_num == 8)
        {
            setLcdPortDb0Name(db0_name);
            setLcdPortDb1Name(db1_name);
            setLcdPortDb2Name(db2_name);
            setLcdPortDb3Name(db3_name);
        }
        setLcdPortDb4Name(db4_name);
        setLcdPortDb5Name(db5_name);
        setLcdPortDb6Name(db6_name);
        setLcdPortDb7Name(db7_name);

        outputPort(pin_e, LOW);
        outputPort(pin_rw, LOW);

        if(bit_mode == 8)
        {
            setPortIOType(pin_db0, IO_OUT);
            setPortIOType(pin_db1, IO_OUT);
            setPortIOType(pin_db2, IO_OUT);
            setPortIOType(pin_db3, IO_OUT);
        }
        setPortIOType(pin_db4, IO_OUT);
        setPortIOType(pin_db5, IO_OUT);
        setPortIOType(pin_db6, IO_OUT);
        setPortIOType(pin_db7, IO_OUT);

        setPortIOType(pin_rs, IO_OUT);
        setPortIOType(pin_rw, IO_OUT);
        setPortIOType(pin_e, IO_OUT);

	DelayMs(40);

        writeLcd(0, 0x30);
        DelayMs(5);
        writeLcd(0, 0x30);
        Delay10us(20);
        writeLcd(0, 0x30);
        Delay10us(20);

        writeLcd(0, 0x20);
        Delay10us(5);

        // Display off
        writeLcd(0, 0x08);
        Delay10us(5);

        // Display on, Cursor off
        writeLcd(0, 0x0C); //writeLcd(0, 0x0D);
        Delay10us(5);

        // Entry Mode Set
        writeLcd(0, 0x06);
        Delay10us(5);

        // Return home
        writeLcd(0, 0x02);
        Delay10us(5);

        //writeLcd(0, 0x01);
        //Delay10us(2);
}

/*******************************************************************************
  Function:
    void updateLcd(void)

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void updateLcd(void)
{
    BYTE i, j;

    // Go home
    writeLcd(0, 0x02);
    DelayMs(2);

    // Output first line
    for(i = 0; i < CHARS_NUM; i++)
    {
        // Erase the rest of the line if a null char is
        // encountered (good for printing strings directly)
        if(lcdText[i] == 0u)
        {
            for(j = i; j < CHARS_NUM; j++)
                lcdText[j] = ' ';
       }
        writeLcd(1, lcdText[i]);
        Delay10us(5);
    }
	
    // Set the address to the second line
    writeLcd(0, 0xC0);
    Delay10us(5);

    // Output second line
    for(i = CHARS_NUM; i < 2 * CHARS_NUM; i++)
    {
        // Erase the rest of the line if a null char is
        // encountered (good for printing strings directly)
        if(lcdText[i] == 0u)
        {
            for(j = i; j < 2 * CHARS_NUM; j++)
                lcdText[j] = ' ';
        }
        writeLcd(1, lcdText[i]);
        Delay10us(5);
    }

    // Set the address to the third line
    writeLcd(0, 0x94);
    Delay10us(5);

    // Output third line
    for(i = 2 * CHARS_NUM; i < 3 * CHARS_NUM; i++)
    {
        // Erase the rest of the line if a null char is
        // encountered (good for printing strings directly)
        if(lcdText[i] == 0u)
        {
            for(j = i; j < 3 * CHARS_NUM; j++)
                lcdText[j] = ' ';
        }
        writeLcd(1, lcdText[i]);
        Delay10us(5);
    }

    // Set the address to the fourth line
    writeLcd(0, 0xD4);
    Delay10us(5);

    // Output fourth line
    for(i = 3 * CHARS_NUM; i < 4 * CHARS_NUM; i++)
    {
        // Erase the rest of the line if a null char is
        // encountered (good for printing strings directly)
        if(lcdText[i] == 0u)
        {
            for(j = i; j < 4 * CHARS_NUM; j++)
                lcdText[j] = ' ';
        }
        writeLcd(1, lcdText[i]);
        Delay10us(5);
    }
}

/*******************************************************************************
  Function:
    void eraseLcd(void)

  Precondition:


  Summary:


  Description:


  Parameters:
    None

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void eraseLcd(void)
{
    // Clear display
    writeLcd(0, 0x01);
    DelayMs(2);

    // Clear local copy
    memset(lcdText, ' ', CHARS_NUM * LINE_NUM);
}

/*******************************************************************************
  Function:
    void writeLineLcd(WORD number, char* line)

  Precondition:


  Summary:


  Description:


  Parameters:
    WORD number
    char* lin

  Return Values:
    None

  Remarks:
    None
*******************************************************************************/
void writeLineLcd(WORD number, char* line)
{
    BYTE i = 0;
    BYTE j = number * CHARS_NUM;

    if(strlen(line) == 20)
    {
        do
        {
            lcdText[j++] = line[i++];
        } while ((lcdText[j - 1] != 0) && (i < strlen(line)));
    }
    else
    {
        do
        {
            lcdText[j++] = line[i++];
        } while ((lcdText[j - 1] != 0) && (j < CHARS_NUM * LINE_NUM - 1));
    }
    
    updateLcd();
}