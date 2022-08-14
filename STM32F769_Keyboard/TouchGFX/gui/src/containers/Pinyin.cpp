#include <gui/containers/Pinyin.hpp>


PinyinParaDef g_Pinyin = { 0 };

/************************************************************************************
Name        :StringCompare()
Description :�ַ����Ƚ�
Input       :str1:���Ƚϵ��ַ���1 str1:���Ƚϵ��ַ���2 len:�Ƚϳ��� 
OutPut      :��
Return      :�ַ�����ȵĳ���
Note        :��
************************************************************************************/
static uint8_t StringCompare(char* str1, char* str2, uint8_t len)
{
	uint8_t comp_len = len;
	uint8_t equal_len = 0;

	while (comp_len)
	{
		if (*str1 == *str2)
		{
			equal_len++;
		}
		else
		{
			if (equal_len != 0)
			{
				break;
			}
		}

		str1++;
		str2++;
		comp_len--;

		if ((*str1 == '\0') || (*str2 == '\0'))
		{
			break;
		}
	}

	return equal_len;
}

/************************************************************************************
Name        :PinyinPageUpdata()
Description :����ҳ
Input       :tanbel_index:ƴ���б�����
OutPut      :��
Return      :��
Note        :��
************************************************************************************/
void PinyinPageUpdata(uint16_t tanbel_index)
{
	uint16_t count = 0;
	wchar_t* p = NULL;

	p = PinyinTable[tanbel_index].Chinese;
	while (*p != NULL)
	{
		p++;
		count++;
	}

	g_Pinyin.PageTotal = count / PINYIN_PAGE_SIZE;	//����ƥ�䵽��ƴ���б��ܹ���ʾ�ĺ���ҳ��
	g_Pinyin.PageReamin = count % PINYIN_PAGE_SIZE;	//�������һҳ�ĺ��ָ���

	if ((g_Pinyin.PageTotal != 0) && (g_Pinyin.PageReamin != 0))
	{
		g_Pinyin.PageTotal += 1;
	}
}

/************************************************************************************
Name        :PinyinToChinese()
Description :ƴ��ת��Ϊ����
Input       :input:������ַ�������	len:����ĳ���
OutPut      :��
Return      :ƴ���б��еĵ�һ��ƥ����
Note        :��
************************************************************************************/
uint16_t PinyinToChinese(char* input, uint8_t len)
{
	uint8_t compare_result = 0;
	uint8_t compare_result_max = 0;

	g_Pinyin.MatchCount = 0;

	for (uint16_t i = 0; i < PINYIN_TABLE_SIZE; i++)	//�������ƥ���ƴ��
	{
		compare_result = StringCompare(input, PinyinTable[i].Number, len);	//�����ַ���ƥ��ĸ���

		if (compare_result > compare_result_max)
		{
			compare_result_max = compare_result;

			g_Pinyin.MatchCount = 0;
			g_Pinyin.MatchIndex[g_Pinyin.MatchCount] = i;
		}
		else if (compare_result == compare_result_max)	//����ж����ͬ��ƥ�����¼��ͬƥ����
		{
			if (len >= 2)
			{
				if (g_Pinyin.MatchCount < (PINYIN_MATCH_MAX - 1))
				{
					g_Pinyin.MatchCount++;
					g_Pinyin.MatchIndex[g_Pinyin.MatchCount] = i;
				}
			}
		}
	}

	return g_Pinyin.MatchIndex[0];
}
