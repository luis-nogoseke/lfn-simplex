/*
 * simplexTypes.h
 *
 *  Created on: 3 de out de 2015
 *      Author: lfnogoseke
 */

#ifndef LFN_SIMPLEX_INCLUDE_SIMPLEXTYPES_H_
#define LFN_SIMPLEX_INCLUDE_SIMPLEXTYPES_H_

#include <vector>
#include <string>

enum type {MAX, MIN};

class SimplexModel{
private:
    std::vector<double> objective;
    std::vector< std::vector<double> > restrictions;
    //std::vector<double> cminusz;

    type modelType;

    void getInitialSolution();
    void checkRestrictions();
    void canonize();

public:
    /* Empty constructor
     * no params
     */
	SimplexModel();

	/* Constructor from text file
	 *params path  path to the input file
	 */
	SimplexModel(std::string path);

	/* Destructor */
	//~SimplexModel();

	bool isOver(const std::vector<double> & cminusz) const;

	void getInitialBase(std::vector<int> & base);

	void iterate(std::vector<int> & base, std::vector<double> & objective,
			     std::vector<std::vector<double>> & restrictions, std::vector<double> & cminusz);

	int getPivot(std::vector<double> & cminusz);

	int getLineThatLeaves(std::vector<std::vector<double>> & restrictions, int pivot);

	void updateBase(std::vector<int> & base, int pivot, int line);

	double solve();
};


#endif /* LFN_SIMPLEX_INCLUDE_SIMPLEXTYPES_H_ */
