main: alive.o animate.o animation.o artifact.o cell.o character.o chest.o connected_room.o coordinate.o door.o evil_tree.o fire_spirit.o snowman.o spider.o witch.o zombie.o enemy.o fire_spirit_hands.o snowman_hands.o spider_legs.o tree_branch.o witch_rod.o zombie_hands.o armor.o axe.o boots.o bow.o hands.o helm.o necklace.o player_rod.o rod.o shield.o sword.o fixed.o floor.o hud.o inanimate.o inputmanager.o item.o item_difensivi.o health_potion.o key.o life_elixir.o rune.o level.o main.o map_handler.o math.o minimap.o pause_menu.o physical.o pixel_art.o player.o projectile.o arrow.o fireball.o snowball.o spell.o room.o start_menu.o comparable.o priority_queue.o priority_queue_room.o queue_coordinate.o room_position.o union_find.o sword.o timer.o wall.o weapon.o
	g++ alive.o animate.o animation.o artifact.o cell.o character.o chest.o connected_room.o coordinate.o door.o evil_tree.o fire_spirit.o snowman.o spider.o witch.o zombie.o enemy.o fire_spirit_hands.o snowman_hands.o spider_legs.o tree_branch.o witch_rod.o zombie_hands.o armor.o axe.o boots.o bow.o hands.o helm.o necklace.o player_rod.o rod.o shield.o sword.o fixed.o floor.o hud.o inanimate.o inputmanager.o item.o item_difensivi.o health_potion.o key.o life_elixir.o rune.o level.o main.o map_handler.o math.o minimap.o pause_menu.o physical.o pixel_art.o player.o projectile.o arrow.o fireball.o snowball.o spell.o room.o start_menu.o comparable.o priority_queue.o priority_queue_room.o queue_coordinate.o room_position.o union_find.o sword.o timer.o wall.o weapon.o -lncurses -o main

alive.o: alive.cpp alive.hpp
	g++ -c alive.cpp
animate.o: animate.cpp animate.hpp
	g++ -c animate.cpp
animation.o: animation.cpp animation.hpp
	g++ -c animation.cpp
artifact.o: artifact.cpp artifact.hpp
	g++ -c artifact.cpp
cell.o: cell.cpp cell.hpp
	g++ -c cell.cpp
character.o: character.cpp character.hpp
	g++ -c character.cpp
chest.o: chest.cpp chest.hpp
	g++ -c chest.cpp
connected_room.o: connected_room.cpp connected_room.hpp
	g++ -c connected_room.cpp
coordinate.o: coordinate.cpp coordinate.hpp
	g++ -c coordinate.cpp
door.o: door.cpp door.hpp
	g++ -c door.cpp
evil_tree.o: enemies/evil_tree.cpp enemies/evil_tree.hpp
	g++ -c enemies/evil_tree.cpp
fire_spirit.o: enemies/fire_spirit.cpp enemies/fire_spirit.hpp
	g++ -c enemies/fire_spirit.cpp
snowman.o: enemies/snowman.cpp enemies/snowman.hpp
	g++ -c enemies/snowman.cpp
spider.o: enemies/spider.cpp enemies/spider.hpp
	g++ -c enemies/spider.cpp
witch.o: enemies/witch.cpp enemies/witch.hpp
	g++ -c enemies/witch.cpp
zombie.o: enemies/zombie.cpp enemies/zombie.hpp
	g++ -c enemies/zombie.cpp
enemy.o: enemy.cpp enemy.hpp
	g++ -c enemy.cpp
fire_spirit_hands.o: enemy_weapons/fire_spirit_hands.cpp enemy_weapons/fire_spirit_hands.hpp
	g++ -c enemy_weapons/fire_spirit_hands.cpp
snowman_hands.o: enemy_weapons/snowman_hands.cpp enemy_weapons/snowman_hands.hpp
	g++ -c enemy_weapons/snowman_hands.cpp
spider_legs.o: enemy_weapons/spider_legs.cpp enemy_weapons/spider_legs.hpp
	g++ -c enemy_weapons/spider_legs.cpp
tree_branch.o: enemy_weapons/tree_branch.cpp enemy_weapons/tree_branch.hpp
	g++ -c enemy_weapons/tree_branch.cpp
witch_rod.o: enemy_weapons/witch_rod.cpp enemy_weapons/witch_rod.hpp
	g++ -c enemy_weapons/witch_rod.cpp
zombie_hands.o: enemy_weapons/zombie_hands.cpp enemy_weapons/zombie_hands.hpp
	g++ -c enemy_weapons/zombie_hands.cpp
armor.o: equipment/armor.cpp equipment/armor.hpp
	g++ -c equipment/armor.cpp
axe.o: equipment/axe.cpp equipment/axe.hpp
	g++ -c equipment/axe.cpp
boots.o: equipment/boots.cpp equipment/boots.hpp
	g++ -c equipment/boots.cpp
bow.o: equipment/bow.cpp equipment/bow.hpp
	g++ -c equipment/bow.cpp
hands.o: equipment/hands.cpp equipment/hands.hpp
	g++ -c equipment/hands.cpp
helm.o: equipment/helm.cpp equipment/helm.hpp
	g++ -c equipment/helm.cpp
necklace.o: equipment/necklace.cpp equipment/necklace.hpp
	g++ -c equipment/necklace.cpp
player_rod.o: equipment/player_rod.cpp equipment/player_rod.hpp
	g++ -c equipment/player_rod.cpp
rod.o: equipment/rod.cpp equipment/rod.hpp
	g++ -c equipment/rod.cpp
shield.o: equipment/shield.cpp equipment/shield.hpp
	g++ -c equipment/shield.cpp
sword.o: equipment/sword.cpp equipment/sword.hpp
	g++ -c equipment/sword.cpp
fixed.o: fixed.cpp fixed.hpp
	g++ -c fixed.cpp
floor.o: floor.cpp floor.hpp
	g++ -c floor.cpp
hud.o: hud.cpp hud.hpp
	g++ -c hud.cpp
inanimate.o: inanimate.cpp inanimate.hpp
	g++ -c inanimate.cpp
inputmanager.o: inputmanager.cpp inputmanager.hpp
	g++ -c inputmanager.cpp
item.o: item.cpp item.hpp
	g++ -c item.cpp
item_difensivi.o: item_difensivi.cpp item_difensivi.hpp
	g++ -c item_difensivi.cpp
health_potion.o: items/health_potion.cpp items/health_potion.hpp
	g++ -c items/health_potion.cpp
key.o: items/key.cpp items/key.hpp
	g++ -c items/key.cpp
life_elixir.o: items/life_elixir.cpp items/life_elixir.hpp
	g++ -c items/life_elixir.cpp
rune.o: items/rune.cpp items/rune.hpp
	g++ -c items/rune.cpp
level.o: level.cpp level.hpp
	g++ -c level.cpp
main.o: main.cpp main.hpp
	g++ -c main.cpp
map_handler.o: map_handler.cpp map_handler.hpp
	g++ -c map_handler.cpp
math.o: math.cpp math.hpp
	g++ -c math.cpp
minimap.o: minimap.cpp minimap.hpp
	g++ -c minimap.cpp
pause_menu.o: pause_menu.cpp pause_menu.hpp
	g++ -c pause_menu.cpp
physical.o: physical.cpp physical.hpp
	g++ -c physical.cpp
pixel_art.o: pixel_art.cpp pixel_art.hpp
	g++ -c pixel_art.cpp
player.o: player.cpp player.hpp
	g++ -c player.cpp
projectile.o: projectile.cpp projectile.hpp
	g++ -c projectile.cpp
arrow.o: projectiles/arrow.cpp projectiles/arrow.hpp
	g++ -c projectiles/arrow.cpp
fireball.o: projectiles/fireball.cpp projectiles/fireball.hpp
	g++ -c projectiles/fireball.cpp
snowball.o: projectiles/snowball.cpp projectiles/snowball.hpp
	g++ -c projectiles/snowball.cpp
spell.o: projectiles/spell.cpp projectiles/spell.hpp
	g++ -c projectiles/spell.cpp
room.o: room.cpp room.hpp
	g++ -c room.cpp
start_menu.o: start_menu.cpp start_menu.hpp
	g++ -c start_menu.cpp
comparable.o: structures/comparable.cpp structures/comparable.hpp
	g++ -c structures/comparable.cpp
priority_queue.o: structures/priority_queue.cpp structures/priority_queue.hpp
	g++ -c structures/priority_queue.cpp
priority_queue_room.o: structures/priority_queue_room.cpp structures/priority_queue_room.hpp
	g++ -c structures/priority_queue_room.cpp
queue_coordinate.o: structures/queue_coordinate.cpp structures/queue_coordinate.hpp
	g++ -c structures/queue_coordinate.cpp
room_position.o: structures/room_position.cpp structures/room_position.hpp
	g++ -c structures/room_position.cpp
union_find.o: structures/union_find.cpp structures/union_find.hpp
	g++ -c structures/union_find.cpp
sword.o: sword.cpp sword.hpp
	g++ -c sword.cpp
timer.o: timer.cpp timer.hpp
	g++ -c timer.cpp
wall.o: wall.cpp wall.hpp
	g++ -c wall.cpp
weapon.o: weapon.cpp weapon.hpp
	g++ -c weapon.cpp



clean:
	rm *.o */*.o main main.exe