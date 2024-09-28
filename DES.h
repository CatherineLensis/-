#include "functions.h"
#include "Key.h"
#include <unordered_map>


std::vector<bool> XOR(std::vector <bool> LR, std::vector <bool> key)
{
	std::vector<bool> result;
	result.resize(LR.size());
	for (int i = 0; i < LR.size(); i++)
	{
		if (LR[i] == key[i])
		{
			result[i] = false;
		}
		else
		{
			result[i] = true;
		}
	}
	return result;
}
std::vector<bool> S4(std::vector <std::vector <bool>> S6)
{
	std::vector <bool> result;
	std::vector <std::vector <bool>> S4; S4.resize(8); for (int i = 0; i < 4; i++) { S4[i].resize(4); }
	std::unordered_map< int, std::vector <bool>> Table
	{
			{ 0, { 0,0,0,0 } }, { 1, {0,0,0,1} }, { 2, {0,0,1,0} }, { 3, {0,0,1,1} }
			, { 4, {0,1,0,0} }, { 5, {0,1,0,1} }, { 6, {0,1,1,0} }, { 7, {0,1,1,1} }
			, { 8, {1,0,0,0} }, { 9, {1,0,0,1} }, { 10, {1,0,1,0} }, { 11, {1,0,1,1} }
			, { 12,{1,1,0,0} }, { 13, {1,1,0,1} }, { 14, {1,1,1,0} }, { 15, {1,1,1,1} }
	};

	std::vector <std::vector <int>> S
	{

		{	14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
			0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
			4, 1, 4, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
			15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},

		{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
			3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
			0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
			13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

		{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
			13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
			13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
			1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },

		{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
			13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
			10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
			3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },

		{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
			14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
			4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
			11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },

		{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
			10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
			9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 1, 6,
			4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },

		{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
			13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
			1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
			6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },

		{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
			1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
			7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
			2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
	};
	for (int i = 0; i < 8; i++)
	{
		int g = S[i][(S6[i][0] * 2 + S6[i][5]) * 16 + (S6[i][1] * 8 + S6[i][2] * 4 + S6[i][3] * 2 + S6[i][4])];
		append(result, Table.at(g));
	}
	return result;
}
std::vector <bool> Extension_Function(std::vector <bool> R)
{
	std::vector <bool> E;
	E.resize(48);
	std::vector <int> Table
	{
			32, 1, 2, 3, 4, 5
			, 4, 5, 6, 7, 8, 9
			, 8, 9, 10, 11, 12, 13
			, 12, 13, 14, 15, 16, 17
			, 16, 17, 18, 19, 20, 21
			, 20, 21, 22, 23, 24, 25
			, 24, 25, 26, 27, 28, 29
			, 28, 29, 30, 31, 32, 1
	};
	for (int i = 0; i < 48; i++)
	{
		E[i] = R[Table[i] - 1];
	}
	return E;
}
std::vector<bool> F(std::vector<bool> R, std::vector<bool> K)
{
	std::vector <bool> RE = Extension_Function(R);
	std::vector <std::vector <bool>> S6; S6.resize(8); for (int i = 0; i < 8; i++) { S6[i].resize(6); }
	std::vector <bool> s4;
	RE = XOR(RE, K);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			S6[i][j] = RE[i * 6 + j];
		}
	};
	s4 = S4(S6);
	return s4;
}
std::vector<std::vector <bool>> Division(std::vector<bool> text)
{
	int N = text.size();
	std::vector<std::vector <bool>> LR;
	LR.resize(2); LR[0].resize(N / 2); LR[1].resize(N / 2);
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
		{
			LR[0][i] = text[i];
		}
		else
		{
			LR[1][i - N / 2] = text[i];
		}
	}
	return LR;
}
std::vector<bool> transposition(std::vector<bool> text, int mode)
{
	std::vector<bool> shuffled_text;
	shuffled_text.resize(64);
	std::vector<int> IP
	{
		58, 50, 42, 34, 26, 18, 10, 2
			, 60, 52, 44, 36, 28, 20, 12, 4
			, 62, 54, 46, 38, 30, 22, 14, 6
			, 64, 56, 48, 40, 32, 24, 16, 8
			, 57, 49, 41, 33, 25, 17, 9, 1
			, 59, 51, 43, 35, 27, 19, 11, 3
			, 61, 53, 45, 37, 29, 21, 13, 5
			, 63, 55, 47, 39, 31, 23, 15, 7
	};
	std::vector<int> IP_1
	{
		40, 8, 48, 16, 56, 24, 64, 32
			, 39, 7, 47, 15, 55, 23, 63, 31
			, 38, 6, 46, 14, 54, 22, 62, 30
			, 37, 5, 45, 13, 53, 21, 61, 29
			, 36, 4, 44, 12, 52, 20, 60, 28
			, 35, 3, 43, 11, 51, 19, 59, 27
			, 34, 2, 42, 10, 50, 18, 58, 26
			, 33, 1, 41, 9, 49, 17, 57, 25
	};

	if (mode == 1)
	{
		for (int i = 0; i < 64; i++)
		{
			shuffled_text[IP[i] - 1] = text[i];
		}
	}
	else
	{
		for (int i = 0; i < 64; i++)
		{
			shuffled_text[IP_1[i] - 1] = text[i];
		}
	}
	return shuffled_text;
}
std::vector<bool> DES(std::vector<bool> text_in_bytes, std::vector<bool> key_in_bits, int trigger)
{
	std::vector<bool> jumbled_text_in_bytes = transposition(text_in_bits, 1);
	std::vector<std::vector<bool>> LR = Division(shuffled_text_in_bits);
	std::vector<std::vector<bool>> round_keys = Round_keys(key_in_bitss);


	std::vector<bool> f;
	std::vector<bool> summ;
	if (trigger == 1)
	{
		for (int i = 0; i < 16; i++)
		{
			f = F(LR[1], round_keys[i]);
			summ = XOR(LR[0], f);
			LR[0] = LR[1];
			LR[1] = summ;
		}
	}
	else
	{
		for (int i = 0; i < 16; i++)
		{
			f = F(LR[0], round_keys[15 - i]);
			summ = XOR(LR[1], f);
			LR[1] = LR[0];
			LR[0] = summ;
		}
	}

	std::vector<bool> Encrypted_shuffled_text_in_bits = Merger(LR);
	std::vector<bool> Encrypted_text_in_bits = transposition(Encrypted_shuffled_text_in_bits, 2);
	return Encrypted_text_in_bits;
}
