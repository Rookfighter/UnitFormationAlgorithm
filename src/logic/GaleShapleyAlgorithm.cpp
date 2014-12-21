#include <algorithm>
#include "logic/GaleShapleyAlgorithm.hpp"
#include "general/Logging.hpp"

namespace ufa
{

	bool operator<(const GaleShapleyRelationship &p_relationship1, const GaleShapleyRelationship &p_relationship2)
	{
		return p_relationship1.distance < p_relationship2.distance;
	}

	GaleShapleyAlgorithm::GaleShapleyAlgorithm()
	{
	}

	GaleShapleyAlgorithm::~GaleShapleyAlgorithm()
	{
	}

	void GaleShapleyAlgorithm::placeUnits(Formation& p_formation)
	{
		init(p_formation);
		pairWomanAndMen();
		applyPositions();
	}

	void GaleShapleyAlgorithm::init(Formation& p_formation)
	{
		formation_ = &p_formation;
		
		currentMan_ = 0;
		
		// create and init women
		women_.resize(formation_->units.size());
		for(int i = 0; i < formation_->units.size(); ++i) {
			women_[i].id = i;
			women_[i].position = formation_->units[i].position;
			women_[i].engagedTo = -1;
		}
		
		// create and init men
		men_.resize(formation_->units.size());
		for(int i = 0; i < formation_->units.size(); ++i) {
			men_[i].id = i;
			men_[i].nextWoman = 0;
			men_[i].engagedTo = -1;
			men_[i].position = formation_->units[i].unit->position;
			men_[i].next = i + 1;
			
			men_[i].preferredWomen.resize(women_.size());
			men_[i].distances.resize(women_.size());
			for(int j = 0; j < women_.size(); ++j) {
				men_[i].preferredWomen[j].womanID = j;
				men_[i].distances[j] = ((formation_->center + women_[j].position) - men_[i].position).lengthSQ();
				men_[i].preferredWomen[j].distance = men_[i].distances[j];
			}

			std::sort(men_[i].preferredWomen.begin(), men_[i].preferredWomen.end());
		}
		men_.back().next = -1;
	}
	
	void GaleShapleyAlgorithm::pairWomanAndMen()
	{
		while(currentMan_ != -1) {
			currentWoman_ = nextPreferredWoman(currentMan_);
			men_[currentMan_].nextWoman++;
			
			//PRINT_INFO("Man %d.", currentMan_);
			
			if(womanIsEngaged(currentWoman_)) {
				int rival = women_[currentWoman_].engagedTo;
				//PRINT_INFO("-- Woman is engaged.");
				//PRINT_INFO("-- Man dist=%.2f; Rival dist = %.2f.", men_[currentMan_].distances[currentWoman_], men_[rival].distances[currentWoman_]);
				
				if(men_[currentMan_].distances[currentWoman_] < men_[rival].distances[currentWoman_]) {
					// current man is more attractive
					//PRINT_INFO("-- Current is more attractive.");
					men_[rival].next = men_[currentMan_].next;
					men_[currentMan_].next = rival;
					men_[rival].engagedTo = -1;
					
					engage(currentMan_, currentWoman_);
				} else {
					// next try
					//PRINT_INFO("-- Next try");
					continue;
				}
			} else {
				// woman is not engaged
				//PRINT_INFO("-- Woman is not engaged.");
				engage(currentMan_, currentWoman_);
			}
			
			currentMan_ = men_[currentMan_].next;
		}
	}
		
	bool GaleShapleyAlgorithm::womanIsEngaged(const int p_woman)
	{
		return women_[p_woman].engagedTo != -1;
	}
	
	int GaleShapleyAlgorithm::nextPreferredWoman(const int p_man)
	{
		int preferredWoman = men_[currentMan_].nextWoman;
		return men_[currentMan_].preferredWomen[preferredWoman].womanID;
	}
	
	void GaleShapleyAlgorithm::engage(const int p_man, const int p_woman)
	{
		men_[p_man].engagedTo = p_woman;
		women_[p_woman].engagedTo = p_man;
	}
	
	void GaleShapleyAlgorithm::applyPositions()
	{
		for(int i = 0; i < formation_->units.size(); ++i) {
			int woman = men_[i].engagedTo;
			formation_->units[i].position = women_[woman].position;
		}
	}

}
