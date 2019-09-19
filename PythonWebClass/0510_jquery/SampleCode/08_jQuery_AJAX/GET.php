<?php

$name = isset($_GET["name"]) ? $_GET["name"] : "";
$age = isset($_GET["age"]) ? $_GET["age"] : "";

echo ('{"Name":"' . $name . '", "Age":' . $age . "}");
