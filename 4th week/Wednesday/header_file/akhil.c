/*
 * akhil.c
 *
 *  Created on: Sep 14, 2022
 *      Author: rs61820
 */
#include<stdio.h>
#include"add.h"
#include"sub.h"
#include"mul.h"
#include"div.h"
int main()
{
	setbuf(stdout,NULL);
	int x,y;
	printf("entr the values");
	scanf("%d %d",&x,&y);
	add(x,y);
	sub(x,y);
	mul(x,y);
	div(x,y);
	return 0;

}


