/*
 * app_command.h
 *
 *  Created on: Mar 9, 2026
 *      Author: dtnb25
 */

#ifndef APP_APP_COMMAND_H_
#define APP_APP_COMMAND_H_


#include <stdint.h>

typedef enum
{
    CMD_NONE = 0,
    CMD_FORWARD,
    CMD_TURN_LEFT,
    CMD_TURN_RIGHT,
    CMD_FORWARD_GYRO,
    CMD_STOP

} command_t;

void Robot_ExecuteCommand(command_t cmd, int value);

void Command_Parse(char *cmd);

#endif /* APP_APP_COMMAND_H_ */
