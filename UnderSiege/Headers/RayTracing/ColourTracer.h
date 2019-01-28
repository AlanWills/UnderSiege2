#pragma once

#include "Tracer.h"


class ColourTracer : public Tracer 
{
	public:
    ColourTracer(World* _worldPtr);
		virtual	~ColourTracer(void);
		
		virtual RGBColor trace_ray(const Ray& ray) const;
};