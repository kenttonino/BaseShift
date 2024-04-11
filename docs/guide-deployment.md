### Deployment Guides
#

```bash
# Manually compile the app.
g++ -o app src/app.cpp

# Run the multipass.
sudo systemctl restart snap.multipass.multipassd.service


# Deploy to snap store.
snapcraft login
snapcraft clean
snapcraft
snapcraft push baseshift_<version-number-in-snapcraft-yaml>_amd64.snap --release=stable
```
