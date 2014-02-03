// UltrasonicDistanceSensor.cpp - Arduino library for retrieving data from ultrasonic distance sensors
// Copyright 2011-2012 Jeroen Doggen (jeroendoggen@gmail.com)
// For more information: variable declaration, changelog,... see UltrasonicDistanceSensor.h
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#include <UltrasonicDistanceSensor.h>

/// Begin function to set default pins
void UltrasonicDistanceSensor::begin()
{
  begin( 2,3 );
}

/// Begin variables
/// - int trigPin: pin used to activate the sensor
/// - int echoPin: pin used to read the reflection
void UltrasonicDistanceSensor::begin( int echoPin, int trigPin ) {
  _trigPin=trigPin;
  _echoPin=echoPin;
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
  setAveraging(1);                                //1: all samples passed to higher level
  _null_distances = 0;
  _null_distances_cnt = 0;
}

/// getDistanceCentimeter(): Returns the distance in centimeters
int UltrasonicDistanceSensor::getDistanceCentimeter() {
	int cm = getDistanceTime() / 58;

	if ( _null_distances_cnt && _null_distances ) {
		for ( int i = 0; i < _null_distances_cnt; i++ ) {
			if ( _null_distances[ i ] == cm ) {
				return 0;
			}
		}
	}

	return cm;
}
