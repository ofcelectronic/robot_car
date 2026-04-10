/*
 * app_command.c
 *
 *  Created on: Mar 7, 2026
 *      Author: dtnb25
 */

#include "app_command.h"
#include "app_robot.h"
#include <stdlib.h>
#include <string.h>

void Robot_ExecuteCommand(command_t cmd, int value)
{
    switch(cmd)
    {

        case CMD_FORWARD:
            Robot_Forward(value);
        break;

        case CMD_FORWARD_GYRO:
            Robot_ForwardGyro(value);
        break;

        case CMD_TURN_LEFT:
            Robot_TurnAngle(value);
        break;

        case CMD_TURN_RIGHT:
            Robot_TurnAngle(-value);
        break;

        case CMD_STOP:
            Robot_Stop();
        break;

        default:
        break;
    }
}

void Command_Parse(char *cmd)
{
    if (cmd == NULL || cmd[0] == '\0')
        return;

    command_t command = CMD_NONE;
    int value = 0;

    switch(cmd[0])
    {

        case 'F':
            command = CMD_FORWARD;
            value = atoi(&cmd[1]);
        break;

        case 'G':
            command = CMD_FORWARD_GYRO;
            value = atoi(&cmd[1]);
        break;

        case 'L':
            command = CMD_TURN_LEFT;
            value = atoi(&cmd[1]);
        break;

        case 'R':
            command = CMD_TURN_RIGHT;
            value = atoi(&cmd[1]);
        break;

        case 'S':
            command = CMD_STOP;
        break;

        default:
        break;
    }

    Robot_ExecuteCommand(command, value);
}
