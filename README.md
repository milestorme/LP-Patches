All of these patches are compiled on Debian Linux. THey are tested for patchability and fully compiled before being added to the repository.
If you are having issues in windows, get Linux Tools and use the patch commands. For help, check out my youtube channel for tutorials on patching properly.

YouTube: https://www.youtube.com/channel/UC5dtyqE5jGkVmuHo5dosHPQ

Official test server:
set realmlist logon.realmsofwarcraft.com
Test realm: Lithordean

Create an account at http://www.realmsofwarcraft.com

I will update this as often as I can. Below is a list of patches.

To donate, go here: http://www.realmsofwarcraft.com/donate.php or make a donation through paypal... realmsofwarcraft@gmail.com

Here is a list of the patches, and a detailed description of each. (Not finished, but working on it.)

* **255_in_who_list.patch** - 3.3.5a is designed for level 70 and the "who" list will only display up to level 99. This allows for higher levels to be displayed.
* **XP-After-Level-100** - If players stop gaining XP after Level 100, use this patch to fix it. This is an old bug and I am unaware whether TC fixed it or not.
* **ArenaGambler.patch** - Someone give me a good description of this. I am assuming you bet on the winner of a battle in an arena.
* **Arena_Template.patch** - This patch replaces 1v1 arena patch. THis has 1v1 and 3v3 arena options.
* **Cheats-FastFishing-AttackAndRespawnSpeed.patch** - Configurable extras such as fast fishing, attack and respawn speed and others. Configs in worldserver.conf.
* **CongratsOnLevel.patch** (broken) - Small script that gives a reward for playing the game. Currently set for 2 items, gold and a spell for each 10 levels obtained.
* **CrossFactionBG.patch** - (broken) Cool but buggy patch that allows a player to choose a different faction for BG. it changes the character to the new faction, giving them skills etc for that faction. Character reverts back to normal after bg finishes. Try not to log out during the battle.
* **Fake_Players.patch** - (broken) Populates the "who" list with up to 49 fake online players. Message appears saying they do not want to be disturbed when whispered to.
* **Fatigue.patch** - Turn on or off the fatigue timer via worldserver.conf setting.
* **Guard-Elite-Honor.patch** - Gain honor from killing elite guards
* **GuildHouses.patch** - (broken) NPC that offers guild leaders a guild house. Once a leader purchases the house, and member of that guild can teleport using this NPC to the guild. Non guild members will not be able to teleport.
* **GuildLevelSystem.patch** - This sets up a cool system where each guild has XP. Players gain XP and that XP is also applied to the guild.
* **Individual-XP-Rate.patch** - Allows setting of different XP rates. I have not tested, so not sure how to set them.
* **KillStreak.patch** - Rewards for pvp based on number of successful wins in a row... I think.
* **Passive_Anticheat.patch** - Best anti cheat out there. checks for speed hacks, flying, etc.
* **Played_time.patch** - Rewards for playing the game, based on how long the player is in realm.
* **Player_Events.patch** - (broken) Rewards based on specific events. Example: Level rewards. First honorable kill rewards. Check readme file for details.
* **NPCBots.patch** - NPCBots patch. NPC's that act like characters, controlled by the server. The run, attack, heal, mount and fly with you.
* **Pvp_ranks.patch** - Ranking system for pvp.
* **Reforging.patch** - Blizzlike reforging Change 40% of your item stats to something else Sends item packets so you can see the changes on item tooltips Simple and easy to use interface Made for 3.3.5a.
* **StartGuild.patch** - Forces new characters into a guild when they are created.
* **Summon_NPC.patch** - Part of the TeleNPC3 script. This is an item, that when right-clicked, will spawn an npc (default entry number 100000). I use it to summon my TeleNPC3 NPC, so players can teleport anywhere any time. The NPC will automatically vanish after a few minutes.
* **TeleNPC3.patch** - The best of the best teleport scripts. an NPC with well organized coordinates for teleporting. You can add catagories, and locations, and restrict those locations in many way, such as by cost, specific guild, level required, etc.
* **Transmogrification.patch** - Transmogrification allows you to change the display of an item to something else. You can use any item in your bags as source of display, as long as it fits the requirements. Requirements can be tweaked in the server configuration file. Basically any item should work with transmogrification. Custom items as well. No item is hardcoded to the system. Has a feature to store sets of displays. This can be removed before compiling or in the configuration file. Made for 3.3.5a.
* **TriniIRC.patch** - Allows players to join a channel (set in config) and chat to people in an IRC channel. Configs are a bit confusing, but once working, you can admin the realm via IRC (so you can connect to IRC on your smartphone, and kick\ban players, chat, and do other commands). On the flip side, you can join the IRC chat room (on your computer, tablet or phone) and chat with in game players.
* **Vote_Rewards.patch** - Rewards system using vote points.
* **WorldChat.patch** - Chat Channel that can be seen by everyone anywhere.

Added some details, but check the website for more information on the patches.
