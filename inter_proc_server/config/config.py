from os import path
from dynaconf import Dynaconf

current_path = path.dirname(path.realpath(__file__))
settings_file = path.join(current_path, "settings.toml")

settings = Dynaconf(
    envvar_prefix="INTER_PROC",
    settings_files=[settings_file]
)

# `envvar_prefix` = export envvars with `export DYNACONF_FOO=bar`.
# `settings_files` = Load this files in the order.
