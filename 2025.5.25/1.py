import json

with open("source.json", "r") as f:
    data = json.load(f)
data = data["currentData"]["problemset"]["problems"]
id = 0
id_total = 0
with open("problem_zh.md", "w") as problem_out:
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

id_total = 0
with open("config.yaml", "w") as answer_out:
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
                answer_out.write(f"    - \"{j["correctAnswers"][0]}\"\n")
                answer_out.write(f"    - {j["score"]}\n")
