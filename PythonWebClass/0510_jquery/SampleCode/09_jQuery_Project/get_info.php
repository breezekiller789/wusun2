<?php

$name = isset($_GET["name"]) ? $_GET["name"] : "";

$db = [];
$db[0]["name"] = "Gary";
$db[0]["age"] = 23;
$db[0]["subtitle"] = "今年 23 歲，仍一事無成";
$db[0]["description"] = "哇啦哇啦哇哇啦哇啦哇哇啦哇啦哇哇啦哇啦哇哇啦哇啦哇哇啦哇啦哇哇啦哇啦哇";

$db[1]["name"] = "Jim";
$db[1]["age"] = 20;
$db[1]["subtitle"] = "今年 20 歲，每天都在考試";
$db[1]["description"] = "好想哭好想哭好想哭好想哭好想哭好想哭好想哭好想哭好想哭好想哭好想哭好想哭";

$db[2]["name"] = "Ray";
$db[2]["age"] = 22;
$db[2]["subtitle"] = "今年 22 歲，過得還蠻爽的";
$db[2]["description"] = "好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔好爽喔";

for ($i = 0; $i < 3; $i++) {
    if ($name == $db[$i]["name"]) {
        echo ('{"Name":"' . $db[$i]["name"]
            . '", "Age":' . $db[$i]["age"]
            . ', "Subtitle":"' . $db[$i]["subtitle"]
            . '", "Description":"' . $db[$i]["description"] . '"}');
    }
}
