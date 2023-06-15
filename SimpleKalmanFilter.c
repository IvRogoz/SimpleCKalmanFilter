#include <math.h>
#include "SimpleKalmanFilter.h"

void SimpleKalmanFilter_init(SimpleKalmanFilter *filter, float mea_e, float est_e, float q) {
    filter->_err_measure = mea_e;
    filter->_err_estimate = est_e;
    filter->_q = q;
}

float SimpleKalmanFilter_updateEstimate(SimpleKalmanFilter *filter, float mea) {
    filter->_kalman_gain = filter->_err_estimate / (filter->_err_estimate + filter->_err_measure);
    filter->_current_estimate = filter->_last_estimate + filter->_kalman_gain * (mea - filter->_last_estimate);
    filter->_err_estimate = (1.0 - filter->_kalman_gain) * filter->_err_estimate + fabs(filter->_last_estimate - filter->_current_estimate) * filter->_q;
    filter->_last_estimate = filter->_current_estimate;

    return filter->_current_estimate;
}

void SimpleKalmanFilter_setMeasurementError(SimpleKalmanFilter *filter, float mea_e) {
    filter->_err_measure = mea_e;
}

void SimpleKalmanFilter_setEstimateError(SimpleKalmanFilter *filter, float est_e) {
    filter->_err_estimate = est_e;
}

void SimpleKalmanFilter_setProcessNoise(SimpleKalmanFilter *filter, float q) {
    filter->_q = q;
}

float SimpleKalmanFilter_getKalmanGain(SimpleKalmanFilter *filter) {
    return filter->_kalman_gain;
}
