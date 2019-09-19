<?php

$name = isset($_POST["name"]) ? $_POST["name"] : "";
$age = isset($_POST["age"]) ? $_POST["age"] : "";

echo ('{"Name":"' . $name . '", "Age":' . $age . "}");
