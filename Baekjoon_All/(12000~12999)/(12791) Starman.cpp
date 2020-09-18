#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() {
	int Q;
	int S, E;
	vector<pair<int, string>> all;
	all.push_back(make_pair(1967, "DavidBowie"));
	all.push_back(make_pair(1969, "SpaceOddity"));
	all.push_back(make_pair(1970, "TheManWhoSoldTheWorld"));
	all.push_back(make_pair(1971, "HunkyDory"));
	all.push_back(make_pair(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"));
	all.push_back(make_pair(1973, "AladdinSane"));
	all.push_back(make_pair(1973, "PinUps"));
	all.push_back(make_pair(1974, "DiamondDogs"));
	all.push_back(make_pair(1975, "YoungAmericans"));
	all.push_back(make_pair(1976, "StationToStation"));
	all.push_back(make_pair(1977, "Low"));
	all.push_back(make_pair(1977, "Heroes"));
	all.push_back(make_pair(1979, "Lodger"));
	all.push_back(make_pair(1980, "ScaryMonstersAndSuperCreeps"));
	all.push_back(make_pair(1983, "LetsDance"));
	all.push_back(make_pair(1984, "Tonight"));
	all.push_back(make_pair(1987, "NeverLetMeDown"));
	all.push_back(make_pair(1993, "BlackTieWhiteNoise"));
	all.push_back(make_pair(1995, "1.Outside"));
	all.push_back(make_pair(1997, "Earthling"));
	all.push_back(make_pair(1999, "Hours"));
	all.push_back(make_pair(2002, "Heathen"));
	all.push_back(make_pair(2003, "Reality"));
	all.push_back(make_pair(2013, "TheNextDay"));
	all.push_back(make_pair(2016, "BlackStar"));
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		vector<int> ans;
		cin >> S >> E;
		for (int j = 0; j < 25; j++) {
			if (all[j].first >= S && all[j].first <= E) {
				ans.push_back(j);
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << all[ans[i]].first << " " << all[ans[i]].second << endl;
		}
	}

	return 0;
}