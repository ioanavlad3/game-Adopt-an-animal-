<h1 align="center">Animal Shelter</h1>

<p align="center">
An interactive application where visitors can find and adopt a pet, and then play a fun game to save it!  
<br>
Built with <strong>C++</strong> and <strong>Raylib</strong>.
</p>

<hr>

<h2>Features</h2>

<h3>Pet Adoption</h3>
<ul>
  <li>Visitors enter their name and search for a pet.</li>
  <li>Search criteria:
    <ul>
      <li>Animal type: <strong>dog</strong> or <strong>cat</strong></li>
      <li>Breed</li>
      <li>Age</li>
      <li>Characteristics (friendly, calm, etc.)</li>
    </ul>
  </li>
  <li>If a match is found, the visitor adopts the pet.</li>
</ul>

<h3>The Game</h3>
<ul>
  <li>The pet is randomly hidden behind one of <strong>4 chests</strong>.</li>
  <li>The player must find it <strong>within 30 seconds</strong> without hitting obstacles.</li>
  <li>Obstacles:
    <ul>
      <li>Random number and random positions</li>
      <li>Hitting one reduces health and costs 1 of your 3 lives</li>
    </ul>
  </li>
  <li>If the player wins, they earn <strong>200 coins</strong>.</li>
  <li>If all lives are lost:
    <ul>
      <li>You can buy an extra life for <strong>100 coins</strong> (if you have enough)</li>
      <li>Otherwise, the game ends</li>
    </ul>
  </li>
  <li>On the main page there’s also a <strong>Mystery Box</strong>:
    <ul>
      <li>Gives a random bonus (happiness, health, energy, coins) and a motivational message</li>
    </ul>
  </li>
</ul>

<h2>Player Stats</h2>
<ul>
  <li><strong>Happiness</strong> decreases if they don’t find the pet</li>
  <li><strong>Energy</strong> decreases every time they play</li>
  <li><strong>Health</strong> decreases when hitting obstacles</li>
</ul>

<hr>

<h2>Classes Overview</h2>

<h3>Animals</h3>
<ul>
  <li>Base: <code>Animal</code>
    <ul>
      <li>Pure virtual methods: <code>makeSound()</code>, <code>displaySound()</code></li>
      <li>Virtual methods for displaying characteristics</li>
    </ul>
  </li>
  <li>Derived:
    <ul>
      <li><code>Dog</code>:
        <ul>
          <li>Breeds: Golden Retriever, Bichon, Poodle, Bulldog</li>
          <li>Overridden <code>makeSound()</code> and <code>displaySound()</code> for each breed</li>
        </ul>
      </li>
      <li><code>Cat</code>:
        <ul>
          <li>Breeds: Sphinx, Siamese, Persian</li>
        </ul>
      </li>
    </ul>
  </li>
  <li>Constructors:
    <ul>
      <li>Name, age, size</li>
      <li>Name, age, size, characteristics</li>
    </ul>
  </li>
  <li>Additional:
    <ul>
      <li>Function to determine size by breed</li>
      <li>Function to validate name & age using exceptions:
        <ul>
          <li><code>SpeciesNotFoundException</code></li>
          <li><code>InvalidAgeException</code></li>
          <li><code>EmptyNameException</code></li>
        </ul>
      </li>
    </ul>
  </li>
</ul>

<h3>Game Logic</h3>
<ul>
  <li>Contains:
    <ul>
      <li>Vector of animals</li>
      <li>Vector of dogs & cats</li>
    </ul>
  </li>
  <li>Functions:
    <ul>
      <li>Add/display animals by type and breed</li>
      <li>Display animal sounds & characteristics</li>
      <li>Randomly generate & place obstacles</li>
      <li>Update obstacles’ movement</li>
      <li>Detect player gender based on name</li>
      <li>Generate random numbers in specific ranges</li>
    </ul>
  </li>
</ul>

<h3>UI</h3>
<ul>
  <li><code>Button</code>:
    <ul>
      <li>Draws the button and detects clicks</li>
      <li>Constructor takes text, coordinates, and size</li>
    </ul>
  </li>
  <li><code>Chest</code>:
    <ul>
      <li>Template class holding either a bonus (<code>int</code>) or a message (<code>string</code>)</li>
    </ul>
  </li>
  <li><code>ChestFactory</code>:
    <ul>
      <li>Uses Factory pattern to create different types of chests (health, energy, happiness, bonus, message)</li>
    </ul>
  </li>
</ul>

<h3>Statistics</h3>
<ul>
  <li><code>Statistics</code>: singleton — each player has only one set of stats.</li>
</ul>

<hr>

<h2>Resources & Inspiration</h2>

<ul>
  <li><a href="https://www.youtube.com/watch?v=RGzj-PF7D74&list=PLwR6ZGPvjVOTIMqUXnqyWaIfQg0xdHNZn&ab_channel=ProgrammingWithNick">Raylib installation & basics</a></li>
  <li><a href="https://www.youtube.com/watch?v=0Ct9ZWEUm7M&list=PLwR6ZGPvjVOTIMqUXnqyWaIfQg0xdHNZn&index=10&ab_channel=ProgrammingWithNick">Buttons tutorial</a></li>
  <li><a href="https://www.tutorialspoint.com/cplusplus/cpp_enumeration.htm">C++ enumerations</a></li>
  <li><a href="https://www.reddit.com/r/raylib/comments/1hs4pg7/trying_to_add_camera_tracking_that_moves_with_the">Camera movement</a></li>
  <li><a href="https://www.raylib.com/examples/text/loader.html?name=text_input_box">Text input</a></li>
  <li><a href="https://github.com/mcmarius/poo/tree/master/tema-3">Design patterns & templates</a></li>
  <li><a href="https://www.geeksforgeeks.org/templates-cpp/">Templates</a></li>
  <li><a href="https://www.geeksforgeeks.org/modern-c-design-patterns-tutorial/">Modern C++ design patterns</a></li>
</ul>

<hr>

<h2>Technologies</h2>
<ul>
  <li>C++</li>
  <li><a href="https://www.raylib.com/">Raylib</a> (graphics library)</li>
</ul>

<hr>
