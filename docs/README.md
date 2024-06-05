# Zappy server

The Zappy's server is made in C. It is the core of the project. The server will manages clients from Zappy's AI and Zappy's GUI. 

### Usage

You have to give several options to launch the server. Here is a list of the options you can use.

```sh
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
	port		is the port number. Default port is 4242.
	width		is the width of the world. Default width is 10.
	height		is the height of the world. Default height is 10.
	name		is the name of the team X. Default name are `Team1`, `Team2`, `Team3`, `Team4`.
	clientsNb	is the number of authorized clients per team. Default clients_nb is 4.
	freq		is the reciprocal of time unit for execution of actions. Default frequency is 100.
```

### Port Configuration

You can configure a port in the range of 1 to 65535 using the -p `port` option. Note that ports between 1 and 1024 require root privileges. To connect to the server, use the localhost IP address and the specified port.

### World Map

You can set the map dimensions between 1 and 100 for both width and height using the -x and -y options. The world map is a square where the inhabitants will reside, and it behaves like a sphere, meaning you cannot go out of bounds.

There are several resources on the map, which can vary in rarity, but there is at least one of each resource type available. Resources will respawn over time based on the frequency setting, ensuring that the total number of resources on the map remains constant. The resources include:

- Food
- Linemate
- Deraumere
- Sibur
- Mendiane
- Phiras
- Thystame

### Team Configuration

You can define up to 10 teams using the -n `name1` `name2` ... option, separating each team name with a space. Note that the name GRAPHIC is reserved for the graphical client and cannot be used as a team name.

### Team Capacity

You can set the team member capacity using the -c `clientsNb` option. Although the capacity can be extended with a fork command, it is limited to a maximum of 100 players connected per team. When a client dies, their spot is returned to the team.

### Frequency

You can set a frequency between 1 and 150 using the -f `freq` option. The frequency controls the simulation tick rate, affecting the timing of commands, food generation, and other events.

### AI Communication Protocol

Inhabitants are players that have access to various commands to comunicate with the server. Here is the list of available commands:

|            Action            |       Command      | Time limit |                 Response                 |
|:----------------------------:|:------------------:|:----------:|:----------------------------------------:|
| move up one tile             | __Forward__        | 7/f        | ok                    					|
| turn 90° right               | __Right__          | 7/f        | ok                    					|
| turn 90° left                | __Left__           | 7/f        | ok                    					|
| look around                  | __Look__           | 7/f        | [tile1, tile2,...]            			|
| inventory                    | __Inventory__      | 1/f        | [linemate n, sibur n, ...]        		|
| broadcast text               | __Broadcast text__ | 7/f        | ok                    					|
| number of team unused slots  | __Connect_nbr__    | -          | value                 					|
| fork a player                | __Fork__           | 42/f       | ok                    					|
| eject players from this tile | __Eject__          | 7/f        | ok/ko                  					|
| death of a player            | _-_                | -          | dead                   					|
| fork a player                | __Fork__           | 42/f       | ok                    					|
| take object                  | __Take object__    | 7/f        | ok/ko                  					|
| set object down              | __Set object__     | 7/f        | ok/ko                  					|
| start incantation            | __Incantation__    | 300/f      | Elevation underway | Current level: k/ko |
| bad/unknown command          | _-_                | -          | ko										|

(Note: The - symbol in the "Time Limit" column indicates that there is no specific time limit for that action.)

> n is number of ressource represend by a number
> k is the player level represented by a number

Also there are severals events that the server can send to AI:

|         Event       |          Response           |
|:-------------------:|:---------------------------:|
| eject: <n>          | Player eject from direction |
| message: <o> <text> | Received message            |
| dead                | Death of the player         |

> n is the direction represented by a number between 1 and 4
> o is the representation represented by a number between 0 and 8
> text is the text sent by the client. It has to be between 1 and 256 characters or the client will received "ko"


### Graphical Communication Protocol

The Graphical Communication Protocol enables the GRAPHICAL client to interact with the server, retrieving and receiving information about the game's state. Here are the commands that can be sent to the server and their corresponding response formats:

| Command |          Description           |           Response Format             |
|:-------:|:------------------------------:|:-------------------------------------:|
| msz     | Get the map size               | msz X Y                               |
| bct X Y | Get the content of a map tile  | bct X Y q0 q1 q2 q3 q4 q5 q6          |
| mct     | Get the content of all the map | Successive `bct` lines (1 per tile)   |
| tna     | Get team names                 | Successive `tna N` lines (1 per team) |
| ppo n   | Get a player's position        | ppo n X Y O                           |
| plv n   | Get a player's level           | plv n L                               |
| pin n   | Get a player's inventory       | pin n X Y q0 q1 q2 q3 q4 q5 q6        |
| sgt     | Get the server frequency       | sgt T                                 |
| sst T   | Change the server frequency    | sst T                                 |


Here are the types of response lines you can receive when logging into GRAPHICAL mode, when a player performs an action, or when the server executes an action:

|         Line received          |          Description          |
|:------------------------------:|:-----------------------------:|
| bct X Y q0 q1 q2 q3 q4 q5 q6   | Tile                          |
| pnw n X Y O L N                | Player connection             |
| ppo n X Y O                    | Player's position             |
| plv n L                        | Player's level                |
| pin n X Y q0 q1 q2 q3 q4 q5 q6 | Player's inventory            |
| pex n                          | Ejection                      |
| pbc n M                        | Broadcast                     |
| pic X Y L n                    | Incantation beginning         |
| pie X Y R                      | Incantation ending            |
| pfk n                          | Egg laying                    |
| pdr n i                        | Resource picked up            |
| pgt n i                        | Resource dropped              |
| pdi n                          | Player death                  |
| enw e n X Y                    | Egg laid by a player          |
| ebo e                          | Player connection from an egg |
| edi e                          | Egg destroyed                 |
| sgt T                          | Time unit modification        |
| seg N                          | End of the game               |
| smg enb X Y                    | Eggs position                 |
| smg Game Paused                | Game paused		    	     |
| smg Game Resumed				 | Game resumed           		 |

> enb is a egg id represented by a number

## Server commands

You can type commands on the server to have action with players.

### Tp command

You can use this command to teleport a player to a position.

Usage: tp `id` `x` `y` `o`
> id is the id of the player
> x and y have to be between the map size
> o is the orientation of the player that have to be a number between 1 and 4

### Give command

You can use this command to give resources in the inventory of a player.

Usage: give `id` `ressource` `quantity`
> id is the id of the player
> ressource have to be between food, linemate, deraumere, sibur, mendiane, phiras, thystame.
> quantity is the number of a resources. It has to be between 1 and 100.

### Kill command

You can use this command to kill a player.

Usage: kill `id`
> id is the id of the player

### Level command

You can use this command to change the level of a player.

Usage: give `id` `level`
> id is the id of the player
> level is represented by a number. It has to be between 1 and 8.

### Tpegg command

You can use this command to teleport an egg to a position.

Usage: tpegg `id` `x` `y`
> id is the id of the egg
> x and y have to be between the map size

### Killegg command

You can use this command to kill an egg.

Usage: killegg `id`
> id is the id of the egg

### Immortal command

You can use this command to controls food management.

Usage: immortal `bool`
> bool is a boolean variable that controls whether food decreases or not. Its value must be either true or false.

### Pause and resume command

You canse use this command to pause the game or resume

Usage: pause
	   resume
