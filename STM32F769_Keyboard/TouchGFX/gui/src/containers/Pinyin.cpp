#include <gui/containers/Pinyin.hpp>


PinyinParaDef g_Pinyin = { 0 };

/************************************************************************************
Name        :StringCompare()
Description :字符串比较
Input       :str1:带比较的字符串1 str1:带比较的字符串2 len:比较长度 
OutPut      :无
Return      :字符串相等的长度
Note        :无
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
Description :更新页
Input       :tanbel_index:拼音列表索引
OutPut      :无
Return      :无
Note        :无
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

	g_Pinyin.PageTotal = count / PINYIN_PAGE_SIZE;	//计算匹配到的拼音列表能够显示的汉字页数
	g_Pinyin.PageReamin = count % PINYIN_PAGE_SIZE;	//计算最后一页的汉字个数

	if ((g_Pinyin.PageTotal != 0) && (g_Pinyin.PageReamin != 0))
	{
		g_Pinyin.PageTotal += 1;
	}
}

/************************************************************************************
Name        :PinyinToChinese()
Description :拼音转化为汉字
Input       :input:输入的字符串数字	len:输入的长度
OutPut      :无
Return      :拼音列表中的第一个匹配项
Note        :无
************************************************************************************/
uint16_t PinyinToChinese(char* input, uint8_t len)
{
	uint8_t compare_result = 0;
	uint8_t compare_result_max = 0;

	g_Pinyin.MatchCount = 0;

	for (uint16_t i = 0; i < PINYIN_TABLE_SIZE; i++)	//查找最佳匹配的拼音
	{
		compare_result = StringCompare(input, PinyinTable[i].Number, len);	//数字字符串匹配的个数

		if (compare_result > compare_result_max)
		{
			compare_result_max = compare_result;

			g_Pinyin.MatchCount = 0;
			g_Pinyin.MatchIndex[g_Pinyin.MatchCount] = i;
		}
		else if (compare_result == compare_result_max)	//如果有多个相同的匹配项，记录相同匹配项
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
