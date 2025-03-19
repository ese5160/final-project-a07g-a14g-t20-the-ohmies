/**********************************************************************//**
* @file      CliThread.h
* @brief     File for the CLI Thread handler. Uses FREERTOS + CLI
* @author    Eduardo Garcia
* @date      2020-02-15

******************************************************************************/

#pragma once

#include "asf.h"
#include "SerialConsole.h"
#include "FreeRTOS_CLI.h"


#define CLI_TASK_SIZE	256		///<STUDENT FILL
#define CLI_PRIORITY (configMAX_PRIORITIES - 1) ///<STUDENT FILL
#define CLI_TASK_DELAY 150	///STUDENT FILL

#define MAX_INPUT_LENGTH_CLI    100	//STUDENT FILL
#define MAX_OUTPUT_LENGTH_CLI   130	//STUDENT FILL

#define CLI_MSG_LEN						16
#define CLI_PC_ESCAPE_CODE_SIZE			4
#define CLI_PC_MIN_ESCAPE_CODE_SIZE		2


#define ASCII_BACKSPACE					0x08
#define ASCII_DELETE                    0x7F
#define ASCII_WHITESPACE				0x20
#define ASCII_ESC						27


BaseType_t xCliClearTerminalScreen( char *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );

#define	CLI_COMMAND_CLEAR_SCREEN		"cls"
#define CLI_HELP_CLEAR_SCREEN			"cls: Clears the terminal screen\r\n"
#define CLI_CALLBACK_CLEAR_SCREEN		(pdCOMMAND_LINE_CALLBACK)xCliClearTerminalScreen
#define CLI_PARAMS_CLEAR_SCREEN			0


// Add near the top of CliThread.h after other #defines
#define FIRMWARE_VERSION "0.0.1"

// Add command definitions for the version command
#define CLI_COMMAND_VERSION          "version"
#define CLI_HELP_VERSION             "version: Prints the firmware version\r\n"
#define CLI_CALLBACK_VERSION         (pdCOMMAND_LINE_CALLBACK)CLI_PrintVersion
#define CLI_PARAMS_VERSION           0

// Add command definitions for the ticks command
#define CLI_COMMAND_TICKS            "ticks"
#define CLI_HELP_TICKS               "ticks: Prints the number of ticks since scheduler start\r\n"
#define CLI_CALLBACK_TICKS           (pdCOMMAND_LINE_CALLBACK)CLI_PrintTicks
#define CLI_PARAMS_TICKS             0

extern SemaphoreHandle_t xRxSemaphore;
void vCommandConsoleTask( void *pvParameters );

BaseType_t CLI_GetImuData( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_OTAU( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_NeotrellisSetLed( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_NeotrellProcessButtonBuffer( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_DistanceSensorGetDistance( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_ResetDevice( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_SendDummyGameData( int8_t *pcWriteBuffer,size_t xWriteBufferLen,const int8_t *pcCommandString );
BaseType_t CLI_PrintVersion(int8_t *pcWriteBuffer, size_t xWriteBufferLen, const int8_t *pcCommandString);
BaseType_t CLI_PrintTicks(int8_t *pcWriteBuffer, size_t xWriteBufferLen, const int8_t *pcCommandString);

