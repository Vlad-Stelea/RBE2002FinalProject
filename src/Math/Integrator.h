/*
 * Integrator.h
 *
 *  Created on: Dec 11, 2018
 *      Author: vlads
 */

#ifndef SRC_MATH_INTEGRATOR_H_
#define SRC_MATH_INTEGRATOR_H_

class Integrator {
public:
	Integrator();
	/**
	 * Integrates based on time
	 * @param x the x value to add to the integration factor
	 */
	double insertIntegration(double x);
	/**
	 * @return the integrated function
	 */
	double getIntegratedValue();
	virtual ~Integrator();
private:
	double previousX;
	long long int previousTime;
};

#endif /* SRC_MATH_INTEGRATOR_H_ */
