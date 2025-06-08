import json
import os
import re
from urllib.parse import unquote
import requests


def work(data, problem_id):
    title = data["currentData"]["problemset"]["name"]
    data = data["currentData"]["problemset"]["problems"]
    id = 0
    id_total = 0
    # 新建题号对应的文件夹
    os.makedirs(f"{problem_id}", exist_ok=True)
    with open(f"{problem_id}/problem_zh.md", "w") as problem_out:
        for i in data:
            id += 1
            problem_out.write(f"{id}. {i["description"]}\n")
            if i["type"] == "MultipleSelection":
                for j in i["questions"]:
                    id_total += 1
                    problem_out.write(f"{"{{ select("}{id_total}{") }}"}\n")
                    for k in j["choices"]:
                        problem_out.write(f"- {k}\n")
                    problem_out.write("\n")
            elif i["type"] == "Blank":
                for j in i["questions"]:
                    id_total += 1
                    problem_out.write(f"{"{{ input("}{id_total}{") }}"}\n")
                    problem_out.write("\n")

    with open(f"{problem_id}/problem.yaml", "w") as problem_out:
        tag1 = ""
        tag2 = ""
        if "NOIP" in title:
            tag1 = "NOIP"
            if "普及组" in title:
                tag2 = "NOIP 普及组"
            elif "提高组" in title:
                tag2 = "NOIP 提高组"
            else:
                tag2 = "NOIP"
        elif "CSP" in title:
            tag1 = "CSP"
            if "入门级" in title:
                tag2 = "CSP 入门级"
            elif "提高级" in title:
                tag2 = "CSP 提高级"
            else:
                tag2 = "CSP"
        else:
            tag1 = "Unknown"
            tag2 = "Unknown"
        problem_out.write(
            f"""pid: T{problem_id}
title: {title}
tag:
  - {tag1}
  - {tag2}"""
        )

    id_total = 0
    os.makedirs(f"{problem_id}/testdata", exist_ok=True)
    with open(f"{problem_id}/testdata/config.yaml", "w") as answer_out:
        answer_out.write("type: objective\nanswers:\n")
        for i in data:
            if i["type"] == "MultipleSelection":
                for j in i["questions"]:
                    id_total += 1
                    answer_out.write(f"  '{id_total}':\n")
                    answer_out.write(f"    - {j["correctAnswers"][0]}\n")
                    answer_out.write(f"    - {j["score"]}\n")
            elif i["type"] == "Blank":
                for j in i["questions"]:
                    id_total += 1
                    answer_out.write(f"  '{id_total}':\n")
                    answer_out.write(f'    - "{j["correctAnswers"][0]}"\n')
                    answer_out.write(f"    - {j["score"]}\n")


def get_json(problem_id):
    url = "https://ti.luogu.com.cn/problemset/" + str(problem_id)
    response = requests.get(
        url,
        headers={
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/128.0.0.0 Safari/537.36 Edg/128.0.0.0"
        },
    )
    try:
        json_data = response.json()
    except:
        match = re.search(
            r'window\._feInjection\s*=\s*JSON\.parse\(decodeURIComponent\("([^"]+)"\)\);',
            response.text,
        )
        if match:
            encoded_text = match.group(1)
            decoded_text = unquote(encoded_text)
            return json.loads(decoded_text)
        else:
            raise Exception("未找到匹配内容")


def get_problem(problem_id):
    json_data = get_json(problem_id)
    work(json_data, problem_id)


if __name__ == "__main__":
    problem_id_st = input("请输入题目ID起点: ")
    problem_id_end = input("请输入题目ID终点: ")
    for i in range(int(problem_id_st), int(problem_id_end) + 1):
        print(f"正在处理题目 {i}...")
        get_problem(i)
        print(f"题目 {i} 处理完成。")
