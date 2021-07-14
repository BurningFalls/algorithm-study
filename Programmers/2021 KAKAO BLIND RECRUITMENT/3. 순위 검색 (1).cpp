#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v[3][2][2][2];
int kind_size[4] = { 2, 1, 1, 1 };
string kind[4][3] = { {"cpp", "java", "python"}, {"backend", "frontend"},
					  {"junior", "senior"}, {"chicken", "pizza"} };

int Find(vector<string> words, int score) {
	int idx[4] = { -1, -1, -1, -1 };
	FOR(i, 0, 3) {
		FOR(j, 0, kind_size[i]) {
			if (words[i] == kind[i][j])
				idx[i] = j;
		}
	}
	int len;
	int cnt = 0;
	if (idx[0] == -1) {
		if (idx[1] == -1) {
			if (idx[2] == -1) {
				if (idx[3] == -1) {
					FOR(i, 0, 2) {
						FOR(j, 0, 1) {
							FOR(k, 0, 1) {
								FOR(m, 0, 1) {
									len = v[i][j][k][m].size();
									FOR(t, 0, len - 1) {
										if (v[i][j][k][m][t] >= score)
											cnt++;
									}
								}
							}
						}
					}
				}
				else if (idx[3] != -1) {
					FOR(i, 0, 2) {
						FOR(j, 0, 1) {
							FOR(k, 0, 1) {
								len = v[i][j][k][idx[3]].size();
								FOR(t, 0, len - 1) {
									if (v[i][j][k][idx[3]][t] >= score)
										cnt++;
								}
							}
						}
					}
				}
			}
			else if (idx[2] != -1) {
				if (idx[3] == -1) {
					FOR(i, 0, 2) {
						FOR(j, 0, 1) {
							FOR(m, 0, 1) {
								len = v[i][j][idx[2]][m].size();
								FOR(t, 0, len - 1) {
									if (v[i][j][idx[2]][m][t] >= score)
										cnt++;
								}
							}
						}
					}
				}
				else if (idx[3] != -1) {
					FOR(i, 0, 2) {
						FOR(j, 0, 1) {
							len = v[i][j][idx[2]][idx[3]].size();
							FOR(t, 0, len - 1) {
								if (v[i][j][idx[2]][idx[3]][t] >= score)
									cnt++;
							}
						}
					}
				}
			}
		}
		else if (idx[1] != -1) {
			if (idx[2] == -1) {
				if (idx[3] == -1) {
					FOR(i, 0, 2) {
						FOR(k, 0, 1) {
							FOR(m, 0, 1) {
								len = v[i][idx[1]][k][m].size();
								FOR(t, 0, len - 1) {
									if (v[i][idx[1]][k][m][t] >= score)
										cnt++;
								}
							}
						}
					}
				}
				else if (idx[3] != -1) {
					FOR(i, 0, 2) {
						FOR(k, 0, 1) {
							len = v[i][idx[1]][k][idx[3]].size();
							FOR(t, 0, len - 1) {
								if (v[i][idx[1]][k][idx[3]][t] >= score)
									cnt++;
							}
						}
					}
				}
			}
			else if (idx[2] != -1) {
				if (idx[3] == -1) {
					FOR(i, 0, 2) {
						FOR(m, 0, 1) {
							len = v[i][idx[1]][idx[2]][m].size();
							FOR(t, 0, len - 1) {
								if (v[i][idx[1]][idx[2]][m][t] >= score)
									cnt++;
							}
						}
					}
				}
				else if (idx[3] != -1) {
					FOR(i, 0, 2) {
						len = v[i][idx[1]][idx[2]][idx[3]].size();
						FOR(t, 0, len - 1) {
							if (v[i][idx[1]][idx[2]][idx[3]][t] >= score)
								cnt++;
						}
					}
				}
			}
		}
	}
	else if (idx[0] != -1) {
		if (idx[1] == -1) {
			if (idx[2] == -1) {
				if (idx[3] == -1) {
					FOR(j, 0, 1) {
						FOR(k, 0, 1) {
							FOR(m, 0, 1) {
								len = v[idx[0]][j][k][m].size();
								FOR(t, 0, len - 1) {
									if (v[idx[0]][j][k][m][t] >= score)
										cnt++;
								}
							}
						}
					}
				}
				else if (idx[3] != -1) {
					FOR(j, 0, 1) {
						FOR(k, 0, 1) {
							len = v[idx[0]][j][k][idx[3]].size();
							FOR(t, 0, len - 1) {
								if (v[idx[0]][j][k][idx[3]][t] >= score)
									cnt++;
							}
						}
					}
				}
			}
			else if (idx[2] != -1) {
				if (idx[3] == -1) {
					FOR(j, 0, 1) {
						FOR(m, 0, 1) {
							len = v[idx[0]][j][idx[2]][m].size();
							FOR(t, 0, len - 1) {
								if (v[idx[0]][j][idx[2]][m][t] >= score)
									cnt++;
							}
						}
					}
				}
				else if (idx[3] != -1) {
					FOR(j, 0, 1) {
						len = v[idx[0]][j][idx[2]][idx[3]].size();
						FOR(t, 0, len - 1) {
							if (v[idx[0]][j][idx[2]][idx[3]][t] >= score)
								cnt++;
						}
					}
				}
			}
		}
		else if (idx[1] != -1) {
			if (idx[2] == -1) {
				if (idx[3] == -1) {
					FOR(k, 0, 1) {
						FOR(m, 0, 1) {
							len = v[idx[0]][idx[1]][k][m].size();
							FOR(t, 0, len - 1) {
								if (v[idx[0]][idx[1]][k][m][t] >= score)
									cnt++;
							}
						}
					}
				}
				else if (idx[3] != -1) {
					FOR(k, 0, 1) {
						len = v[idx[0]][idx[1]][k][idx[3]].size();
						FOR(t, 0, len - 1) {
							if (v[idx[0]][idx[1]][k][idx[3]][t] >= score)
								cnt++;
						}
					}
				}
			}
			else if (idx[2] != -1) {
				if (idx[3] == -1) {
					FOR(m, 0, 1) {
						len = v[idx[0]][idx[1]][idx[2]][m].size();
						FOR(t, 0, len - 1) {
							if (v[idx[0]][idx[1]][idx[2]][m][t] >= score)
								cnt++;
						}
					}
				}
				else if (idx[3] != -1) {
					len = v[idx[0]][idx[1]][idx[2]][idx[3]].size();
					FOR(t, 0, len - 1) {
						if (v[idx[0]][idx[1]][idx[2]][idx[3]][t] >= score)
							cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	int info_len = info.size();
	FOR(t, 0, info_len - 1) {
		string is = info[t];
		int is_len = is.size();
		vector<string> word_v;
		string tmp = "";
		int score = 0;
		FOR(i, 0, is_len - 1) {
			if (is[i] == ' ') {
				word_v.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += is[i];
			}
		}
		int idx[4] = { 0, };
		score = stoi(tmp);
		FOR(i, 0, 3) {
			FOR(j, 0, kind_size[i]) {
				if (word_v[i] == kind[i][j])
					idx[i] = j;
			}
		}
		v[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
	}

	int query_len = query.size();
	FOR(t, 0, query_len - 1) {
		string qs = query[t];
		int qs_len = qs.size();
		vector<string> word_v;
		string tmp = "";
		int score = 0;
		FOR(i, 0, qs_len - 1) {
			if (qs[i] == ' ') {
				if (tmp != "and")
					word_v.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += qs[i];
			}
		}
		score = stoi(tmp);
		int result = Find(word_v, score);
		answer.push_back(result);
	}

	return answer;
}