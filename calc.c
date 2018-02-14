
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
	bool c_flag = false;
	int k;
	int add = 0, subtract = 0, multiply = 0, divide = 0, help = 0;
	
	while((k = getopt(argc, argv, "admsh")) != -1){
		switch (k){
			case 'a':
			if(c_flag){
				printf("%s\n", "Cannot select multiple operations");
				break;
			}
			c_flag = true;
			add = 1;
			break;
			case 'd':
			if(c_flag){
				printf("%s\n", "Cannot select multiple operations");
				break;
			}
			c_flag = true;
			divide =1;
			break;
			case 'm':
			if(c_flag){
				printf("%s\n", "Cannot select multiple operations");
				break;
			}
			c_flag = true;
			multiply =1;
			break;
			case 's':
			if(c_flag){
				printf("%s\n", "Cannot select multiple operations");
				break;
			}
			c_flag = true;
			subtract = 1;
			break;
			case 'h':
			if(c_flag){
				printf("%s\n", "Cannot select multiple operations");
				break;
			}
			c_flag = true;
			help = 1;
			break;
			} 
		}
	if(argc < 2){
		printf("%s\n", "not enough arguments");
		return 0;
	}
	if(c_flag == true && add == 1){
		int sum = atoi(argv[2]);
		for(int i = 3; i < argc; i++){
			sum += atoi(argv[i]);
		}
		printf("%d\n", sum);
		return sum;
	}
	if(c_flag == true && subtract == 1){
		int difference = atoi(argv[2]);
		for(int i = 3; i < argc; i++){
			difference -= atoi(argv[i]);
		}
		printf("%d\n", difference);
		return difference;
	}
	if(c_flag == true && multiply == 1){
		int product = atoi(argv[2]);
		for(int i = 3; i < argc; i++){
			// printf("%d\n", result);
			product *= atoi(argv[i]);
		}
		printf("%d\n", product);
		return product;

	}
	if(c_flag == true && divide == 1){
		int quotient = atoi(argv[2]);
		for (int i = 3; i < argc; i++)
		{
			quotient /= atoi(argv[i]);
		}
		printf("%d\n", quotient);
		return quotient;
	}
	if(c_flag == true && help == 1){
		printf("%s\n", "type -a, with integers followed after, to add the integers, type -s, with integers followed after to, to subtract the integers, type -m, with integers followed after, to multiply the integers, type -d, with integers followed after, to divide the integers, type -h for help" );
	}

}