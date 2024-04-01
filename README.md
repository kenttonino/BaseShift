### Description
##

![Screenshot from 2024-03-22 18-36-21](https://github.com/kentlouisetonino/baseshift/assets/69438999/eea07703-ef56-4b46-bd24-b281f715b5c7)


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
##
> - Note: `The root main.go is a symbolic link`.

> - Build and run the app.

```bash
# Change permission for the build script.
sudo chmod +x run.sh

# Run the app.
./run
```

<br />
<br />



### Installation
#

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
