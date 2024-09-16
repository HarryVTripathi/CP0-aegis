
with open("b.txt", "r+") as f:
    lines = f.readlines()


c, p = lines[0].split()
c, p = int(c), int(p)

contribs = {}

skill_to_contrib_map = {}

contrib_index = 1
contrib_counter = 0

while contrib_index<len(lines):
    contrib_counter += 1
    if contrib_counter > c:
        break
    print(lines[contrib_index].split())
    name, num_of_skills = lines[contrib_index].split()
    num_of_skills = int(num_of_skills)
    contribs[name] = {}
    for index in range(contrib_index + 1, contrib_index + 1 + num_of_skills):
        
        skill, level = lines[index].split()
        level = int(level)
        if skill not in skill_to_contrib_map:
            skill_to_contrib_map[skill] = {}
        skill_to_contrib_map[skill][name] = level
        contribs[name][skill] = level
    contrib_index += num_of_skills + 1

class Project:
    def __init__(self, name, days, score, deadline, people) -> None:
        self.name = name
        self.days = days
        self.score = score
        self.deadline = deadline
        self.people = people
        self.skillAndLevelMap = {}
        self.roles = []

    def __repr__(self) -> str:
        return """
        self.name = """ + str(self.name) + """
        self.days = """ + str( self.days) + """
        self.score = """ + str(self.score) + """
        self.deadline = """ + str(self.deadline) + """
        self.people = """ + str(self.people) + """
        self.skillAndLevelMap : """ + str(self.skillAndLevelMap) + """
        """


projects = []

for project in range(0, p):
    name, days, score, deadline, people = lines[contrib_index].split()
    days, score, deadline, people = int(days), int(score), int(deadline), int(people)
    project = Project(name, days, score, deadline, people)
    for i in range(contrib_index+1, contrib_index+1 + people):
        skill, level = lines[i].split()
        project.roles.append(skill)
        level = int(level)
        project.skillAndLevelMap[skill] = level
    projects.append(project)
    contrib_index += people + 1


# print(contribs)
# print(projects)
projects.sort(key=lambda x:x.days)



output = []

num_of_projects = 0
for project in projects:
    ifWeTake = project.name
    dontTake = False
    roleTaken = []
    for skill in project.roles:
        if skill not in skill_to_contrib_map:
            dontTake = True
            break
        people = skill_to_contrib_map[skill]
        max_person = max(people, key=lambda peep:contribs[peep][skill])
        roleTaken.append(max_person)
    if dontTake:
        continue
    roleTaken = " ".join(roleTaken)
    num_of_projects += 1
    output.append(ifWeTake)
    output.append(roleTaken)

output = [str(num_of_projects)] + output

print(output)
output = "\n".join(output)

with open("b.out", "w+") as f:
    f.writelines(output)


