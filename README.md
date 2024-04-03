### Description
#

![Screenshot from 2024-04-01 21-52-52](https://github.com/kentlouisetonino/baseshift/assets/69438999/d03f0b99-d39d-426b-a10a-00d8a9dad649)



<br />

> - A CLI tool for converting number systems.

> - This will support binary, decimal, octal, and hexadecimal systems.

> - Snap : https://snapcraft.io/baseshift

<br />
<br />



### System Design
#

![base-shift-system-design](https://github.com/kentlouisetonino/baseshift/assets/69438999/13c7d142-0186-417d-94fa-192f96fdac0d)

<br />
<br />



### Local Development
#
> - Note: `The root main.go is a symbolic link`.

> - Build and run the app.

```bash
# Change permission for the build script.
sudo chmod +x run.sh

# Run the app.
./run
```

> - Below are the installation commands.

```bash
# If app is already installed.
sudo snap refresh baseshift

# If app is not yet installed.
sudo snap install baseshift

# Remove the app using snap.
sudo snap remove baseshift

# Running the app.
baseshift
```
