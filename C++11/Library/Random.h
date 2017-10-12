


#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <random>

namespace Random_Example
{
	//TODO
	//http://en.cppreference.com/w/cpp/header/random
	//different engines.

	void RandomSimple()
	{
		std::random_device	rd;
		std::mt19937		gen(rd());

		//Random Uniform Int
		std::uniform_int_distribution<int> uniformIntDistribution(1, 6);
		int randomResult0 = uniformIntDistribution(rd);

		std::uniform_real_distribution<float> uniformRealDistribution(1, 6);
		float randomResult1 = uniformRealDistribution(rd);

		std::bernoulli_distribution bernoulliDistribution(0.25);
		bool randomResult2 = bernoulliDistribution(gen);

		std::binomial_distribution<int> binomialDistribution(1, 6);
		int randomResult3 = binomialDistribution(rd);

		std::negative_binomial_distribution<int> negativeBinomialDistribution(1, 6);
		int randomResult4 = negativeBinomialDistribution(rd);

		std::geometric_distribution<> geometricDistribution;
		int randomResult5 = geometricDistribution(gen);

		std::poisson_distribution<> poissonDistribution(4);
		int randomResult6 = poissonDistribution(gen);

		std::exponential_distribution<> exponentialDistribution(4);
		double randomResult7 = exponentialDistribution(gen);

		std::gamma_distribution<> gammaDistribution(4);
		double randomResult8 = gammaDistribution(gen);

		std::weibull_distribution<> weibullDistribution(4);
		double randomResult9 = weibullDistribution(gen);

		std::extreme_value_distribution<> extremeValueDistribution(4);
		double randomResult10 = extremeValueDistribution(gen);

		std::normal_distribution<> normalDistribution(4);
		double randomResult11 = normalDistribution(gen);

		std::lognormal_distribution<> lognormalDistribution(4);
		double randomResult12 = lognormalDistribution(gen);

		std::extreme_value_distribution<> chiSquaredDistribution(4);
		double randomResult13 = chiSquaredDistribution(gen);

		std::extreme_value_distribution<> cauchyDistribution(4);
		double randomResult14 = cauchyDistribution(gen);

		std::extreme_value_distribution<> fisherFDistribution(4);
		double randomResult15 = fisherFDistribution(gen);

		std::extreme_value_distribution<> studentTDistribution(4);
		double randomResult16 = studentTDistribution(gen);

		std::discrete_distribution<> discreteDistribution(1,4);
		int randomResult17 = discreteDistribution(gen);

		std::vector<double> piecewise_i{ 0,  1, 5, 10 };
		std::vector<double> piecewise_w{ 1,  0,  1 };
		std::piecewise_constant_distribution<> piecewiseConstantDistribution(piecewise_i.begin(), piecewise_i.end(), piecewise_w.begin());
		double randomResult18 = piecewiseConstantDistribution(gen);

		std::piecewise_linear_distribution<> piecewiseLinearDistribution(piecewise_i.begin(), piecewise_i.end(), piecewise_w.begin());
		double randomResult19 = piecewiseLinearDistribution(gen);
		
		//Simpler random without class object
		double randomResult20 = std::generate_canonical<double, 10>(gen);
		
		//Seed Generation
		std::seed_seq seedSeq{ 1,2,3,4,5 };
		std::vector<std::uint32_t> seeds(10);
		seedSeq.generate(seeds.begin(), seeds.end());
	}

}

//#endif