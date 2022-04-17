SET
@Entry	:= 601017,
@Model := 22953, -- Male Belf in t5
@Name := "DRFaggot",
@Title := "Seventy Booster",
@Icon := "Speak",
@GossipMenu := 0,
@MinLevel := 1,
@MaxLevel := 80,
@Faction := 35,
@NPCFlag := 80,
@Scale := 1.5,
@Rank := 0,
@Type := 7,
@TypeFlags := 0,
@FlagsExtra := 2,
@AIName		:= "SmartAI",
@Script 	:= "npc_ac_70_skip";

-- NPC
DELETE FROM creature_template WHERE entry = @Entry;
INSERT INTO creature_template (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `RegenHealth`, `flags_extra`, `AiName`, `ScriptName`) VALUES
(@Entry, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1.14286, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 1, @FlagsExtra, @AIName, @Script);

-- NPC EQUIPPED
DELETE FROM `creature_equip_template` WHERE `CreatureID`=@Entry AND `ID`=1;
INSERT INTO `creature_equip_template` VALUES (@Entry, 1, 30095, 28825, 0, 0); -- Leo Wep + ALD

-- creatture_template_movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (@Entry);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(@Entry, 1, 1, 0, 0, 0, 0, NULL);