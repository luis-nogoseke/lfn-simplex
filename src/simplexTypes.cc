#include "simplexTypes.h"



SimplexModel::SimplexModel():objective{6, 5, 0, 0}, modelType(MAX), restrictions{{1, 1, 1, 0, 5},{3, 2, 0, 1, 12}}{}

SimplexModel::SimplexModel(std::string path){
 //TODO
	;
}

double SimplexModel::solve(){
    double ans=0;
    double theta = 0;
    std::vector<double> cminusz(objective.size());
    std::vector<int> base(restrictions.size());

    getInitialBase(base);
    iterate(base, objective, restrictions, cminusz);

	while(!isOver(cminusz)){
        int pivotIndex = getPivot(cminusz);
        int line = getLineThatLeaves(restrictions, pivotIndex);
        double aux_val = restrictions[line][pivotIndex];
        for(auto & x : restrictions[line]){
                		    x = x/aux_val;
          }


        for(auto & res : restrictions){
        	//If it is the line that leaves
        	if (res != restrictions[line]){
        		double aux_val = res[pivotIndex];
        		for(int i = 0; i < res.size(); ++i)
        		    res[i] = res[i]-(restrictions[line][i]*aux_val);
        	}
        }
        updateBase(base, pivotIndex, line);
        iterate(base, objective, restrictions, cminusz);
    }
	for( int i =0; i< base.size(); ++i){
        ans += objective[base[i]]*restrictions[i].back();
	}
    return ans;
}


void SimplexModel::updateBase(std::vector<int> & base, int pivot, int line){
    base[line] = pivot;
}

int SimplexModel::getLineThatLeaves(std::vector<std::vector<double>> & restrictions, int pivot){
    int lineindex=0;
    double theta=restrictions[0].back()/restrictions[0][pivot];

    for(int i =0 ; i < restrictions.size(); ++i){
    	if(restrictions[i].back()/restrictions[i][pivot]< theta){
    		// b/(pivot element)
    		theta = restrictions[i].back() /restrictions[i][pivot];
    		lineindex = i;
    	}
    }
    return lineindex;
}

int SimplexModel::getPivot(std::vector<double> & cminusz){
	double max = 0;
	int pivot=0;
	for (int i = 0; i< cminusz.size(); ++i){
		if (cminusz[i] > max){
			max = cminusz[i];
			 pivot = i;
		}
	}
	return pivot;
}


bool SimplexModel::isOver(const std::vector<double> & cminusz) const{
	bool teste  = true;
	for (auto it : cminusz){
		if (it > 0){
			teste = false;
		}
	}
	return teste;
}

void SimplexModel::getInitialBase(std::vector<int> & base){
	base[0] = 2;
	base[1] = 3;

}

void SimplexModel::iterate(std::vector<int> & base, std::vector<double> & objective,
			     std::vector<std::vector<double>> & restrictions, std::vector<double> & cminusz){
	for (int i = 0 ; i<restrictions[1].size(); ++i){
		double aux=0;
		for (int j = 0; j<base.size(); ++j){
		    aux += objective[base[j]]*restrictions[j][i];
		}
		cminusz[i] = objective[i] - aux;
	}

}

