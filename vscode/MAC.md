# Git
- use Apple Git
```
    $ git --version
    git version 2.15.1 (Apple Git-101)
```
- configure Git
 - ref: git-scm.com/book/en/v2/Getting-Started-First-Time-Git-Setup
```
    $ git config --global user.name "your name"
    $ git config --global user.email your.account@mail.somewhere
    $ git config --global core.editor of_your_choise (e.g. "/usr/bin/vim")
    $ git config --list
    credential.helper=osxkeychain
    user.name=Toshiro Miyamoto
    user.email=toshiro.en.miyamoto@gmail.com
    core.editor=/usr/bin/vim
```
- generate your SSH public key
 - ref: git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key
```
    $ mkdir ~/.ssh
    $ cd ~/.ssh
    $ ssh-keygen
    Generating public/private rsa key pair.
    Enter file in which to save the key (/c/Users/yourID/.ssh/id_rsa): <<depress Enter>>
    Enter passphrase (empty for no passphrase): <<your passphrase>>
    Enter same passphrase again: <<your passphrase>>
    Your identification has been saved in /c/Users/yourID/.ssh/id_rsa.
    Your public key has been saved in /c/Users/yourID/.ssh/id_rsa.pub.
```
- register the public key in your GitHub.com account

# Apple Command Line Tools
- Home-brew requires the tool
- developer.apple.com/download/more/
- Command Line Tools (macOS 10.13) for X code
- install the tool
```
    $ g++ --version
    Configured with:
     --prefix=/Library/Developer/CommandLineTools/usr
     --with-gxx-include-dir=/usr/include/c++/4.2.1
    Apple LLVM version 9.1.0 (clang-902.0.39.1)
    Target: x86_64-apple-darwin17.5.0
    Thread model: posix
    InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

# Home-brew
- brew.sh
- install home-brew
```
    $ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
- check version
```
$ brew --version
Homebrew 1.5.13
Homebrew/homebrew-core (git revision 41dd; last commit 2018-03-31)
```

$ Open JDK
- ref: https://github.com/AdoptOpenJDK/homebrew-openjdk
- install the latest JDK
```
    $ brew tap AdoptOpenJDK/openjdk
    $ brew install adoptopenjdk-openjdk10
```

