SET
@Entry	:= 601017,
@Model := 22953, -- Male Belf in t5
@Name := "Booster Mcgee",
@Title := "Seventy Booster",
@Icon := "Speak",
@GossipMenu := 0,
@MinLevel := 80,
@MaxLevel := 80,
@Faction := 35,
@NPCFlag := 1,
@Scale := 1.5,
@Rank := 0,
@Type := 7,
@TypeFlags := 0,
@FlagsExtra := 0,
@AIName		:= "",
@Script 	:= "npc_ac_70_skip";

-- NPC
DELETE FROM creature_template WHERE entry = @Entry;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `DamageModifier`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(@Entry, 0, 0, 0, 0, 0, @Model, 0, 0, 0, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, 0, @Faction, @NPCFlag, 1, 1.14286, 0.25, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, @AIName, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, @Script, 0);

-- NPC EQUIPPED
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@Entry AND `ID`=1;
INSERT INTO `creature_equip_template` VALUES (@Entry, 1, 30095, 28825, 0, 0); -- Leo Wep + ALD

-- creatture_template_movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (@Entry);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@Entry, 1, 1, 0, 0, 0, 0, NULL);


-- BEGIN LVL 80 SKIP

SET
@Entry	:= 601018,
@Model := 22953, -- Male Belf in t5
@Name := "Rooster the Booster",
@Title := "Eighty Booster",
@Icon := "Speak",
@GossipMenu := 0,
@MinLevel := 80,
@MaxLevel := 80,
@Faction := 35,
@NPCFlag := 1,
@Scale := 1.5,
@Rank := 0,
@Type := 7,
@TypeFlags := 0,
@FlagsExtra := 0,
@AIName		:= "",
@Script 	:= "npc_ac_80_skip";

-- NPC
DELETE FROM creature_template WHERE entry = @Entry;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `DamageModifier`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(@Entry, 0, 0, 0, 0, 0, @Model, 0, 0, 0, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, 0, @Faction, @NPCFlag, 1, 1.14286, 0.25, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, @AIName, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, @Script, 0);

-- NPC EQUIPPED
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@Entry AND `ID`=1;
INSERT INTO `creature_equip_template` VALUES (@Entry, 1, 30095, 28825, 0, 0); -- Leo Wep + ALD

-- creatture_template_movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (@Entry);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@Entry, 1, 1, 0, 0, 0, 0, NULL);