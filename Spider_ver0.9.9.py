import os
import re
import requests
from bs4 import BeautifulSoup
headers = {'User-Agent':'ETW', 'Referer':'Chrome'}

def process_0(orig_list):
    out = []
    for i in orig_list:
        #element = BeautifulSoup(i, "html.parser")
        element = i.stripped_strings
        for x in element:
            out.append(x)
    return out

def process_summary(orig_list):
    out = []
    if top != 0:
        for k in range(0,top):
            out.append('无数据')
    for i in orig_list:
        #element = BeautifulSoup(i, "html.parser")
        element = i.strings
        for x in element:
            if x == '\n':
                x = '无数据'
            else:
                x = x.strip()
            out.append(x)
    return out

def process_time(orig_list):
    out = []
    if top != 0:
        for k in range(0,top):
            out.append('无数据')
    for i in orig_list:
        #element = BeautifulSoup(i, "html.parser")
        element = i.stripped_strings
        for x in element:
            out.append(x)
    return out

def process_author(orig_list):
    out = []
    for i in orig_list:
        #element = BeautifulSoup(i, "html.parser")
        element = i.span.parent['title']
        out.append(element)
    return out

def process_replyer(orig_list_):
    out = []
    if top != 0:
        for k in range(0,top):
            out.append('最后回复人:无数据')
    for j in orig_list_:
        #element = BeautifulSoup(i, "html.parser")
        element = j.parent.span['title']
        out.append(element)
    return out

#rel="noreferrer"
#class="j_th_tit "

tieba = input('请输入一个贴吧名:')


file = requests.get('https://tieba.baidu.com/f',{'kw':tieba, 'fr':'index'},headers=headers)
text = BeautifulSoup(file.text,"html.parser")

top_1 = text.find_all(attrs={'class':"icon-top"}).__len__()
top_2 =text.find_all(attrs={'class':"icon-member-top"}).__len__()
top = top_1 + top_2


title_o = text.find_all('a',attrs={'class':"j_th_tit "})
#author_o = text.find_all(attrs={'class':"tb_icon_author " or "tb_icon_author no_icon_author"})
author_o = text.find_all(class_ = re.compile("tb_icon_author "))#处理 title="主题作者: 我是客观分析者"
#tb_icon_author no_icon_author
#
create_time_o = text.find_all('span',attrs={'class':"pull-right is_show_create_time"})
reply_num_o = text.find_all('span',attrs={'class':"threadlist_rep_num center_text"})
summary_o = text.find_all(attrs={'class':"threadlist_abs threadlist_abs_onlyline "})
#,attrs={'class':"threadlist_abs threadlist_abs_onlyline "}
#threadlist_detail clearfix
#,attrs={'class':"threadlist_detail clearfix"}
last_replyer_o = text.find_all('span',attrs={'class':"tb_icon_author_rely j_replyer"})#处理 title="最后回复人: hhbasdw"
last_reply_time_o = text.find_all('span',attrs={'class':"threadlist_reply_date pull_right j_reply_data"})

title = process_0(title_o)
reply_num = process_0(reply_num_o)
summary = process_summary(summary_o)
last_reply_time = process_time(last_reply_time_o)
create_time = process_0(create_time_o)

author = process_author(author_o)
last_replyer = process_replyer(last_replyer_o)

for i in range(0,title.__len__()):
    print('回帖数:', reply_num[i], '    主题:', title[i], '    ', author[i], '    创建时间:', create_time[i] )
    print('主题概览:', summary[i])
    print(last_replyer[i], '    最后回复时间:', last_reply_time[i],'\n')

stop = input('按回车键结束……')
#Bug:红名检测不到   解决√
#print(last_replyer)
#print(text)
#print(file.text)
