//
// Created by Bong Jian Shen on 25/06/2020.
//


#include "com_example_hangman_GameActivity.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int LED_ON(int number)
{
    short value;
    int ret;
    int fd_led= -1;
    int bit = 127;
    int init = 0;
    if (number > 9 || number < 1) return 0;
    fd_led = open("/dev/fpga_led", O_RDWR);
    if(fd_led == -1) return 0;
    ret = read(fd_led, &value, sizeof(value));


    /*for( int i = 0 ; i < number ; i++)
    {
        bit = bit << 1;
        bit = bit + 1;
    }*/
    value = bit;

    ret = write(fd_led, &value, sizeof(value));
    close(fd_led);
    return ret;
}

int LED_OFF(int number)
{
    short value;
    int ret;
    int fd_led = -1;
    int bit = 1;
    int times = 1;

    if (number > 9 || number < 0) return 0;
    fd_led = open("/dev/fpga_led", O_RDWR);
    if(fd_led == -1) return 0;
    ret = read(fd_led, &value, sizeof(value));

    for (int i = 0; i < number-1 ; i++)
    {
        bit = bit << 1;
        bit = bit + 1;
    }

    if(number == 0)
    {
        bit = 0;
    }
    value = bit;

    ret = write(fd_led, &value, sizeof(value));
    close(fd_led);
    return ret;
}

JNIEXPORT void JNICALL Java_com_example_hangman_GameActivity_turnOnLed
        (JNIEnv *env, jobject this_ptr, jint led)
{
    LED_ON(led);
}


JNIEXPORT void JNICALL Java_com_example_hangman_GameActivity_turnOffLed
        (JNIEnv *env, jobject this_ptr,jint led)
{
    LED_OFF(led);
}