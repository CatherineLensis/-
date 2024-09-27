#include <vector>
#include "string"
#include <unordered_map>

std::vector<char> bits2bytes(const std::vector<bool>& bits)
{
	// ����� ��� ������ ����������.
	size_t byte_num = bits.size() / 8;
	if (bits.size() % 8 > 0) byte_num++;
	// ����� ��� ������ ����������. �� ��������� �������� ���� ��� ��������������� � FALSE.
	std::vector<char> bytes(byte_num, 0x00);
	// ���� �� ������ ������.
	for (int i = 0; i < bits.size(); i++) {
		// ������ �������� �����.
		int byte_idx = i / 8;
		// ������ �������� ���� � �����.
		int bit_idx = i % 8;
		// ���� ������� ��� ����� TRUE, �� ��� ���� ��������� � TRUE. 
		if (bits[i]) bytes[byte_idx] |= (0x01 << (7 - bit_idx));
	}
	return bytes;
}
std::vector<bool> bytes2bits(const std::vector<char>& bytes)
{
	// ����� ��� ������ ����������.
	std::vector<bool> bits(bytes.size() * 8);
	// ���� �� ������ ������.
	for (int byte_idx = 0; byte_idx < bytes.size(); byte_idx++) {
		// ���� �� ����� �������� �����.
		for (int bit_idx = 0; bit_idx < 8; bit_idx++) {
			// ��������� �������� ����.
			bits[byte_idx * 8 + bit_idx] = ((bytes[byte_idx] >> (7 - bit_idx)) & 0x01);
		}
	}
	return bits;
}
void append(std::vector<bool>& body, const std::vector<bool>& tale)
{
	body.insert(body.end(), tale.begin(), tale.end());
}
void append(std::vector<bool>& body, char tale)
{
	// ���� �� ����� � ����������� �����.
	for (int bit_idx = 0; bit_idx < 8; bit_idx++)
	{
		// ���������� �������� ����.
		body.emplace_back((tale >> (7 - bit_idx)) & 0x01);
	}
}
std::vector<bool> ��16�2(std::string �����)
{
	std::vector<bool> result;
	std::unordered_map< char, std::vector <bool>> Table
	{
			{ '0', { 0,0,0,0 } }, { '1' , {0,0,0,1}}, { '2', {0,0,1,0}}, { '3', {0,0,1,1}}
			, { '4', {0,1,0,0} }, { '5', {0,1,0,1} }, { '6', {0,1,1,0} }, { '7', {0,1,1,1} }
			, { '8', {1,0,0,0} }, { '9', {1,0,0,1} }, { 'A', {1,0,1,0} }, { 'B', {1,0,1,1} }
			, { 'C',{1,1,0,0} }, { 'D', {1,1,0,1} }, { 'E', {1,1,1,0} }, { 'F', {1,1,1,1} }
	};
	for (int i = 0; i < �����.size(); i++)
	{
		append(result, Table[�����[i]]);
	}
	return result;
}
std::string ��2�16(std::vector<bool> �����)
{
	std::string result;
	std::unordered_map< std::vector <bool>, char> Table
	{
				{ {0,0,0,0}, '0'}, {{0,0,0,1}, '1' }, {{0,0,1,0}, '2' }, {{0,0,1,1}, '3' }
			,	{ {0,1,0,0}, '4'}, {{0,1,0,1}, '5' }, {{0,1,1,0}, '6' }, {{0,1,1,1}, '7' }
			,	{ {1,0,0,0}, '8'}, {{1,0,0,1}, '9' }, {{1,0,1,0}, 'A' }, {{1,0,1,1}, 'B' }
			,	{ {1,1,0,0}, 'C'}, {{1,1,0,1}, 'D' }, {{1,1,1,0}, 'E' }, {{1,1,1,1}, 'F' }
	};
	std::vector<bool> ������; ������.resize(4);
	for (int i = 0; i < �����.size() / 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			������[j] = �����[i * 4 + j];
		}
		result.push_back(Table[������]);
	}
	return result;
}


bool ���������_���()
{
	int ��� = rand()%2;
	if (��� == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::string ���������_�����()
{
	std::string ����_�_16;
	std::vector<bool> �����_�_���;
	std::vector<bool> ����_�_�����;
	�����_�_���.resize(8);
	for (int i = 0; i < 8; i++)
	{
		int n = 0;
		for (int j = 0; j < 7; j++)
		{
			�����_�_���[j] = ���������_���();
			n += �����_�_���[j];
		}
		�����_�_���[7] = (n + 1) % 2;
		append(����_�_�����, �����_�_���);
	}
	����_�_16 = ��2�16(����_�_�����);
	return  ����_�_16;
}
std::vector<char> ����������_�_���������_���������(std::vector<char> �����)
{
	std::vector<char> ����� = �����;
	int n = �����.size();
	if (�����.size() % 8 != 0)
	{
		n = �����.size() % 8;
	}
	for (int i = 0; i < 8 - n; i++)
	{
		�����.push_back(' ');
	}
	return �����;
}
std::vector<std::vector <bool>> �������_��_�������_�_�������_��������(std::vector <bool> �����)
{
	std::vector<std::vector <bool>> �����; �����.resize(�����.size() / 64);
	std::vector <bool> �����; �����.resize(64); 
	for (int ������_����� = 0; ������_����� < �����.size()/64; ������_�����++)
	{
		for (int ������_����� = 0; ������_����� < 64; ������_�����++)
		{
			�����[������_�����] = �����[������_����� * 64 + ������_�����];
		}
		�����[������_�����] = �����;
	}
	return �����;
}

