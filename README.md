### csci330group
All projects for team Synth Dolphin

# Directory
Project 1 is our bowling score tracker

# GitHub general use rules:

  **To set up branch to push/pull from:**
  
  1. Clone branch - creates a copy of code (automatically creates origin remote and remote-tracking branch):
    ```git clone https://github.com/USERNAME/REPOSITORY.git```
  2. Creating a remote (which is an alternative name for the repo URL):
    ```git remote add origin https://github.com/USERNAME/REPOSITORY.git```
  where "origin" is name of remote.
      * To change the url of the remote, use: ```git remote set-url origin https://github.com/USERNAME/REPOSITORY.git```
  3. Create a branch to work on the code in:
    ```git checkout -b <my branch name>```
  4. Set push upstream for new branch:
    ```git push -u origin <my branch name>.```
      * -u stands for set-upstream

**General use commands:**
  
  1. Get updates from GitHub's remote branches:
    ```git pull origin <my branch name>```
    which updates the branch you're currently on.
      * To get get changes but not apply updates (so you can review changes): ```git fetch origin```
  2. Store recent changes in your local repo before submission:
    ```git commit -m "I am a useful and concise message"```
  3. Send changes (commits) from local repo to branch in GitHub:
    ```git push origin <my branch name>```
  4. Merge changes of your current branch with another:
    ```git merge branchname```
      * Often used to update local branch with changes from remote branch.
      
### Please remember to pull and update before you start work
