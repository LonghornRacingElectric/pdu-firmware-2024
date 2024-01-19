#ifndef PDU_FIRMWARE_VCU_H
#define PDU_FIRMWARE_VCU_H

/**
 * Initialize CAN communication with vcu.
 */
void vcu_can_init();

/**
 * Send IMU accleration data over CAN. Precision is 0.01 m/s^2.
 * @param accel_x
 * @param accel_y
 * @param accel_z
 */
void vcu_send_accel(float accel_x, float accel_y, float accel_z);

/**
 * Send IMU gyroscope data over CAN. Precision is 0.01 rad/s.
 * @param gyro_x
 * @param gyro_y
 * @param gyro_z
 */
void vcu_send_gyro(float gyro_x, float gyro_y, float gyro_z);

#endif //PDU_FIRMWARE_VCU_H
