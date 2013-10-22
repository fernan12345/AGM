#pragma once

#include <agm_behavior.h>
#include <agm_model.h>
#include <agm_modelSymbols.h>
#include <agm_modelEdge.h>
#include <agm_modelConverter.h>


class AGM
{
public:
	AGM(std::string pddlFileFull_, std::string pddlFilePartial_);
	void print();

	bool checkModel(AGMModel::SPtr model);
	bool proposeModel(AGMModel::SPtr model);
	bool updateModel(AGMModelSymbol);

	std::string pddlProblemForTarget(const AGMModel::SPtr &target, int32_t unknowns, const std::string domainName, const std::string problemName);

// private:
	std::string pddlFileFull, pddlFilePartial;
	std::string fullPDDLContent, partialPDDLContent;
	AGMModel currentModel;
	void loadFromFile(std::string pddlFileFull_, std::string pddlFilePartial_);

private:
	void readFileToString(std::string &file, std::string &content);

};


