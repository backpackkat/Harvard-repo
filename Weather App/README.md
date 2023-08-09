---
files: [index.html; test.js; style.css; src/;]
window: [terminal]

---
README:
# Thesis // Final Project: Backpackkat's 5-Day Weather App
# Backpackkat's 5-day Weather App!
## url: [https://clever-kataifi-206433.netlify.app/]
## 3-Minute Video Demo Walkthrough: [https://youtu.be/aECDiCQE908]

-- Create 5-Day Mobile Weather App with Responsive Design. --
-- this README explains design choices, app features, and outlines my thought process below. If you have any questions, feel free to get in touch: katecodes.io@gmail.com

# Understanding
Why did I go in this direction, this idea, this app?
I knew I wanted to blend my newly found back-end skills with my love of travel, all things pretty, and front-end design. While working alone and having learned a ton in a short period of time, I had SO many ideas, it was quite difficult to narrow down the possibilities at first - my eyes were a lot larger than my stomach, so to speak! However, this seemed like an attainable yet challenging goal for my perfectionist brain to set my sights on, which explains why I went in this direction. I could either turn in a half-baked idea that was not very good in execution, or perhaps not the most original idea that let me practice my skills to the best of my ability, allowing creativity to shine through. So that's what I did, and while you'll see I still found multiple things I'd have liked to flesh out more fully/do differently, I am quite happy with the results of V1.0.

## HTML:
index.html: this is where everything is organized, tied/linked together, image sources included. If one link is off, the entire app looks broken. So this piece is CRUCIAL to get right. scripts must be correctly allocated here, the STRUCTURE of the page is designed here (which is why there are a ton of divs and classes and ids - I set it up that way in anticipation of the mass amounts of CSS customization that was coming). This is also where I put the search bar form, link to my Github, etc. -  all the STATIC text you see on the page. (dynamic text shows up due to js functions, if I coded it correctly, which I did, of course!)

I ran into MANY, MANY ISSUES with this file; coding it was simple enough, but once it was structured, EDITING IT without breaking the entire app was an ordeal in and of itself. 

Exhibit A: especially around the 5-day forecast div.row and the centralized circle holding the currentDay forecast (changing one variable without breaking the entire page was a major ordeal for me, until I got more comfortable and if I'm being honest with myself, learned to slow down and look at what I changed.

Exhibit B: I was able to code the ‘feels-like’ weather function in my JS file, eventually; but every-time I tried to insert it into my front-end, I either broke my entire app, or hated how it looked. So, I left it in my JS as a reminder to myself to come back to it and try to find a way to fix it in the future. (as we all know, coding is never complete!)

## CSS:
style.css: This is where everything came together stylistically to look as beautiful as it does. All the colours, the fonts, the behaviours, the gradients, the positions, the borders, literally everything any item on the page DOES - is controlled by this page (except input/output - that's done in js). But in terms of aesthetics, this is the homebase. 

Colors: I knew I wanted a travel theme when designing, but when I thought about it, what does "travel" mean, aesthetically? Ok, so I can put a compass dial to reflect location, Done. But subtletly in design is usually more successful, especially in corporate/commercial settings (and I want this in my portfolio!) So I thought about it, and landed on somewhere that is completely opposite to where I'm from: Japan. I love sushi, and I knew food wasn't going up there. I knew I also wanted something bright & cheerful when the user visited the app, so, Cherry Blossoms. 

I custom-designed all the flowers in Figma, which took a while, even though I have some experience. From there, the color scheme & gradients followed naturally. I played around with different schemes a LOT - I had to ensure that the scheme fit with both the blossoms and made the weather icons pop. 

Although my CSS is rather long and complicated, I feel it reflects good design choices and a superior User Experience on the Front End..


## JAVASCRIPT:
test.js: (this is going to be a long one!) 

First, I ensured some global variables.

Then, I laid out my functions. 

The first important one to discuss is getForecast // displayForecast. This allows me to take a response object, retrieve the daily forecast data from it, generate HTML markup for (up to) the first 6 forecast days, and inserts the generated HTML into the specified element on the page. This is important because it’s every single piece of data that is reflected along the bottom of the weather app, or in other words, the 5-day weather forecast, all in 1 function, which is what I was trying to achieve. It took much research, drafts, and speaking with people who know much more than I did about JS when I began this journey for me to be able to insert HTML into my JS functions, but I am grateful I now know this trick.

Moving along, a feature to search city, show temp and weather condition. (Function showCity) // 
This function was quite complicated to complete: it receives a response object containing weather data, extracts relevant info like temp, weather cond’s, city name, wind speed, etc. The function then updates corresponding HTML elements on the page with retrieved data. It displays current weather conditions related to the city that was queried.

It’s complicated by the number of variables required to complete it, and I definitely had trouble figuring out exactly what was required (read: wanted to throw my computer out the window more than several times) but we got there in the end. 
Included is a portion of code to change icons according to the weather, which I thought was a nice touch.

Also included is a feature to find weather for any city in the world (findCity) and preventRefresh (prevents form refresh until manual override—so user can look at weather forecast results as long as they want) (self-explanatory, I hope).

Moving along, the longest function included is to show the current weather (showCurrentWeather or SCW). This ended up being very similar to showCity with a few subtle differences. SCW displays today’s forecast; icons (which change again, weather-dependent); has HTML elements related to the forecast display. The key difference between showCity is that this function is focused on the present time.

This is my longest function in the script and makes sense that it took me the longest to get right. I had trouble with some of the innerHTML’s showing on the app correctly - a lot of researching was done and troubleshooting - but I got there in the end.

Next, we have a feature to get current location and show temperature (retrievePosition).
Using a similar API call above, we grab the lat/long coordinates to get a users’ location, or, users can click on the compass provided in the app’s interface to show location connected to the browser’s geolocation system (I believe that’s how geolocation works—not an expert).

findCity(“Vienna”);
I’ve also provided a default location for the app to begin with: Vienna (voted “best city in the world to live in, 2023”). 

Last but not least, we have our temperature converter, because we still have a few hold-outs throughout the globe; so our last function will be to convert any temp from C to F & back again. It also ensures the default temp is C.

**The feels-like was 100% the hardest part, only because I added it at the last minute, and it required a complete rebuild of my script AND my HTML. (it doesn’t fit in my circle, so if you notice, I’ve deliberately left it off the app for now - but intend to go back and code it in someday).**


Issues: I did not get to include the "feels like" temperature on this app, as time and other commitments have come calling. I began to code and therefore included them but don't yet know how to tie it all together. The rest of the app functions as intended and I'm really proud of what I've learned & accomplished from the beginning of the course until now.

Other Unresolved issues: 
⁃	Changing C - F (and back) in the 5-day forecast - F change works properly in “current time” but will not translate to the 5-day forecast. Unclear why.
⁃	Changing Light to Dark Mode depending on time
⁃	Changing background depending on Location (would love to show Mountains for Geneva, or the Opera House for Sydney, for example - v2.0!)
⁃	Displaying "feels like" in round circle without breaking entire app
⁃	Displaying 'footer' (it’s coded but will not display properly within the app boundaries and I cannot figure out why)
  
After about 4 weeks and countless edits, I finally stepped away from the keys for good. I am happy with where my app is.
 
The process was really frustrating, but also great for me - I watched countless Youtube tutorials, read books, looked up functions on websites, talked to mentors face-to-face, rewrote things 100x over, and can honestly say I'm extremely proud of what I've put forward here. Is it perfect? Of course not. (see Unresolved Issues above).

Do I already have ideas to make V2.0? Absolutely. (see every Unresolved Issue Above). I guess that's software development for you. And it means I'm on the right path, so thank you Harvard!).

-KU.
