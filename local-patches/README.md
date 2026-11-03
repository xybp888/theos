# Local Theos changes

The `master` branch follows RootHide Theos. The headers and Logos fixes are
tracked as patches because `vendor/include` and `vendor/logos` are upstream
submodules. Apply both patches after initializing a fresh checkout:

```sh
git submodule update --init --recursive
git -C vendor/include apply --check ../../local-patches/include.patch
git -C vendor/logos apply --check ../../local-patches/logos.patch
git -C vendor/include apply ../../local-patches/include.patch
git -C vendor/logos apply ../../local-patches/logos.patch
```

Keep a clean checkout for merging updates. If the patches are applied in that
checkout, reverse them before updating the submodules. First save any further
edits to the patches so the reverse operation also accounts for those edits.

```sh
git -C vendor/include apply -R ../../local-patches/include.patch
git -C vendor/logos apply -R ../../local-patches/logos.patch
git fetch upstream
git merge upstream/master
git submodule update --init --recursive
```

Then run the patch checks and apply the patches again. If an upstream change
causes a check to fail, review the affected hunk against the new submodule
revision before applying it. Commit changes to the main repository or patch
files on `master` and push that branch to your own remote.
