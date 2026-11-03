# Local Theos changes

Initialize the remaining submodules after cloning.

```sh
git submodule update --init --recursive
```

The source in `vendor/include` and `vendor/logos` is tracked directly in
this repository. The `bin/logos.pl` entry point runs the vendored Logos
and loads its property generator from
`vendor/logos/bin/lib/Logos/Generator/Base/Property.pm`.

When updating a checkout that still has these two paths initialized as
submodules, save any edits in those submodules first, then run the following
from the old revision.

```sh
git submodule deinit -- vendor/include vendor/logos
git pull --ff-only
git submodule update --init --recursive
```

For upstream updates, fetch and merge RootHide Theos. If the upstream merge
reports a conflict at either vendored directory, keep the tracked source
directory and omit the matching submodule entry from `.gitmodules`. Review
the upstream submodule revision changes separately and merge any source
updates into the tracked directories.

```sh
git remote add upstream https://github.com/roothide/theos.git
git fetch upstream
git merge upstream/master
```

Add the `upstream` remote only when it is missing. The original upstream
revisions of both directories are recorded in the source import commit.
