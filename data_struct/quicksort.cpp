#include <iostream>

using namespace std;

int sa[500] = {
	499,497,495,493,491,489,487,485,483,481,479,477,475,473,471,470,472,474,476,478,480,482,484,486,488,490,492,494,496,498,469,467,465,463,461,459,457,455,453,451,449,447,445,443,441,440,442,444,446,448,450,452,454,456,458,460,462,464,466,468,439,437,435,433,431,429,427,425,423,421,419,417,415,413,411,410,412,414,416,418,420,422,424,426,428,430,432,434,436,438,409,407,405,403,401,399,397,395,393,391,389,387,385,383,381,380,382,384,386,388,390,392,394,396,398,400,402,404,406,408,379,377,375,373,371,369,367,365,363,361,359,357,355,353,351,350,352,354,356,358,360,362,364,366,368,370,372,374,376,378,349,347,345,343,341,339,337,335,333,331,329,327,325,323,321,320,322,324,326,328,330,332,334,336,338,340,342,344,346,348,319,317,315,313,311,309,307,305,303,301,299,297,295,293,291,290,292,294,296,298,300,302,304,306,308,310,312,314,316,318,289,287,285,283,281,279,277,275,273,271,269,267,265,263,261,260,262,264,266,268,270,272,274,276,278,280,282,284,286,288,259,257,255,253,251,249,247,245,243,241,239,237,235,233,231,230,232,234,236,238,240,242,244,246,248,250,252,254,256,258,229,227,225,223,221,219,217,215,213,211,209,207,205,203,201,200,202,204,206,208,210,212,214,216,218,220,222,224,226,228,199,197,195,193,191,189,187,185,183,181,179,177,175,173,171,170,172,174,176,178,180,182,184,186,188,190,192,194,196,198,169,167,165,163,161,159,157,155,153,151,149,147,145,143,141,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,139,137,135,133,131,129,127,125,123,121,119,117,115,113,111,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,109,107,105,103,101,99,97,95,93,91,89,87,85,83,81,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,79,77,75,73,71,69,67,65,63,61,59,57,55,53,51,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,49,47,45,43,41,39,37,35,33,31,29,27,25,23,21,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,19,17,15,13,11,9,7,5,3,1,0,2,4,6,8,10,12,14,16,18
};

void swap2(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void quickSort(int s, int e) {
	if (s >= e)
		return ;
	int pivot = sa[s];;
	int start = s + 1;
	int end = e - 1;
	while (start <= end) {
		while (pivot < sa[end])
			end--;
		while (pivot > sa[start] && start <= end)
			start++;
		if (start < end)
			swap2(sa[start], sa[end]);
		start++;
	}
	if (pivot > sa[end]) 
		swap2(sa[s], sa[end]);
	quickSort(s, end);
	quickSort(end + 1, e);
}

int main()
{
	quickSort(0, 500);
	for (int i = 1; i < 500; ++i) {
		if (sa[i] < sa[i - 1]) {
			cout << "error\n";
			return 0;
		}
	}
	cout << "done\n";
}