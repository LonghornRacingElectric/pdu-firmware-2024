#include "vcu.h"
#include "angel_can.h"
#include "angel_can_ids.h"

static CanOutbox currents_outbox;
static CanOutbox imu_accel_outbox;
static CanOutbox imu_gyro_outbox;


void vcu_can_init(){
    can_addOutbox(PDU_VCU_LV_CURRENTS, 1.0f, &currents_outbox);
    can_addOutbox(PDU_VCU_IMU_ACCEL, 0.25f, &imu_accel_outbox);
    can_addOutbox(PDU_VCU_IMU_GYRO, 0.25f, &imu_gyro_outbox);
}

void vcu_send_currents(float treetrunk, float radfan, float battfan, float pump1, float pump2, float glv, float shdn, float bl){
    currents_outbox.data[0] = (uint8_t) (treetrunk * 10);
    currents_outbox.data[1] = (uint8_t) (radfan * 10);
    currents_outbox.data[2] = (uint8_t) (battfan * 10);
    currents_outbox.data[3] = (uint8_t) (pump1 * 10);
    currents_outbox.data[4] = (uint8_t) (pump2 * 10);
    currents_outbox.data[5] = (uint8_t) (glv * 10);
    currents_outbox.data[6] = (uint8_t) (shdn * 10);
    currents_outbox.data[7] = (uint8_t) (bl * 10);
    currents_outbox.isRecent = true;
}

void vcu_send_accel(float accel_x, float accel_y, float accel_z){
    can_writeBytes(imu_accel_outbox.data, 0, 1, (int16_t) (accel_x * 100));
    can_writeBytes(imu_accel_outbox.data, 2, 3, (int16_t) (accel_y * 100));
    can_writeBytes(imu_accel_outbox.data, 4, 5, (int16_t) (accel_z * 100));
    imu_accel_outbox.isRecent = true;
}

void vcu_send_gyro(float gyro_x, float gyro_y, float gyro_z){
    can_writeBytes(imu_gyro_outbox.data, 0, 1, (int16_t) (gyro_x * 100));
    can_writeBytes(imu_gyro_outbox.data, 2, 3, (int16_t) (gyro_y * 100));
    can_writeBytes(imu_gyro_outbox.data, 4, 5, (int16_t) (gyro_z * 100));
    imu_gyro_outbox.isRecent = true;
}


