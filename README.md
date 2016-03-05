<snippet>
<content><![DATA[
# ${1:IRCBOT}

IRCBOT is a basic lib for IRC.
This lib can deal with the basic problem in network,and make an interface for your bot to IRC.
And all the lib was written in C++.

##Functions

At the first, you need to create a new object of IRCbot which defines under ircBot.h file.
And when you construct that you may need some parameter for the function that defines as the following.

IRCbot(string nick, string target)

You need to fill the nickName for the robot and the domain for IRC server.

You need to fill the nickName for the robot and the domain for IRC server.

void joinChannel(string channel)

Use sendMes2C() function can send the message to any channel which you want if you yet join the channel, the function will join the channel which you yet join.

void sendMes2C(string mes, string channelSend)

Use isConnected() can get a boolean for known if the network connected.

bool isCUse isConnected() can get a boolean for known if the network connected.

bool isConnected()


And if you want to receive the message from IRC, you can use recveve() function that will return a string.
But if there is no any message all program will stop to wait for the message, so you must be careful for this.

string recveve()

## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D


