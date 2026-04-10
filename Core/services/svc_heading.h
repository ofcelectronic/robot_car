/*
 * svc_heading.h
 *
 *  Created on: Mar 4, 2026
 *      Author: dtnb25
 */

#ifndef SERVICES_SVC_HEADING_H_
#define SERVICES_SVC_HEADING_H_

void Heading_Init(void);
void Heading_Update(void);

float Heading_GetYaw(void);
float Heading_GetPitch(void);
float Heading_GetRoll(void);
void Heading_Calibrate(void);
void Heading_Print(void);
float Heading_GetTemp(void);
void TestWhoAmI(uint8_t who);

#endif /* SERVICES_SVC_HEADING_H_ */
