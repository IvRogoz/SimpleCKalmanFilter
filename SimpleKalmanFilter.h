#ifndef SimpleKalmanFilter_h
#define SimpleKalmanFilter_h

typedef struct SimpleKalmanFilter {
    float _err_measure;
    float _err_estimate;
    float _q;
    float _current_estimate;
    float _last_estimate;
    float _kalman_gain;
} SimpleKalmanFilter;

void SimpleKalmanFilter_init(SimpleKalmanFilter *filter, float mea_e, float est_e, float q);
float SimpleKalmanFilter_updateEstimate(SimpleKalmanFilter *filter, float mea);
void SimpleKalmanFilter_setMeasurementError(SimpleKalmanFilter *filter, float mea_e);
void SimpleKalmanFilter_setEstimateError(SimpleKalmanFilter *filter, float est_e);
void SimpleKalmanFilter_setProcessNoise(SimpleKalmanFilter *filter, float q);
float SimpleKalmanFilter_getKalmanGain(SimpleKalmanFilter *filter);

#endif
