#include "mbed/mbed.h"
#include "LSM6DS33/LSM6DS33.h"
#include "MadgwickAHRS/MadgwickAHRS.h"
#include "PID/PIDcontroller.h"


LSM6DS33 sensor(p9, p10, LSM6DS33_AG_I2C_ADDR(1));

Timer tmain;

float ax, ay, az, gx, gy, gz;   //Sensor value

int main(){
    sensor.begin();

    double timeLog = 0;
    tmain.start();
    timeLog += tmain.read();

    double mainPeriod = 0.01;

    serial.printf("begin DroneControll\r\n");

    while(1){

        /*
        ------------------Read Section------------------------------------------------
        */
        sensor.readAll();
        ax = sensor.ax;
        ay = sensor.ay;
        az = sensor.az;
        gx = sensor.gx;
        gy = sensor.gy;
        gz = sensor.gz;
        serial.printf("IMU: ax:%f, ay:%f, az:%f, gx:%f, gy:%f, gz:%f", ax, ay, az, gx, gy, gz);
    } 

}


