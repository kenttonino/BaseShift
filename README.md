### Description
#

![Screenshot from 2024-05-03 19-59-07](https://github.com/kentlouisetonino/baseshift/assets/69438999/d323b572-8dae-4f9e-bf75-15d038a5df0b)

<br />

> - A CLI tool that converts number system.

> - This will support binary, decimal, octal, and hexadecimal systems.

> - Snap : https://snapcraft.io/baseshift

> - If you want to check how I made this project from scratch, you can <br />
    view it [here](https://www.youtube.com/playlist?list=PLPks-uiro_XLkNPKPjwAcL6ifiqpIIPgu). Spoiler alert, it's pretty boring.

<br />
<br />



### System Design
#

<br />

![System Design](./docs/image-system-design.gif)

<br />
<br />



### Local Development
#
> - Note: `The root main.go is a symbolic link`.

> - Run the app.

```bash
# Change permission for the run script.
sudo chmod +x run.sh

# Run the app.
./run.sh
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
