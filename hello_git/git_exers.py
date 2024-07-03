# Saved as .py just to differentiate comments

# Getting started using command line interface...  https://www.w3schools.com/git/default.asp and https://cs50.harvard.edu/web/2020/weeks/1/
mkdir myproject
cd myproject

git init 
Initialized empty Git repository in /Users/user/myproject/.git/

git status

git status --short
# Note: Short status flags are:

# ?? - Untracked files
# A - Files added to stage
# M - Modified files
# D - Deleted files

ls
myproject.py

# Stage all new, modified, and deleted files. Use the shorthand command:
git add -A

# or
git add myproject.py

# Commit the changes to the current repository with message
git commit -m "Create myproject.py"

# We are working in our local repository, and we do not want to disturb or possibly wreck the main project.
# Create new branch
git branch myproject_new_feature
git checkout myproject_new_feature

# or create if not existing the branch using checkout -b
git checkout -b emergency-fix
Switched to a new branch 'emergency-fix'

git checkout myproject_new_feature
# Now we have moved our current workspace from the master branch, to the new branch


# clear files after adding them to .gitignore:
git rm --cached <filename/foldername> -r       

# example, after creating a virtual environment called 'venv' which is also a directory and adding it to .gitignore:
git rm --cached venv -r       