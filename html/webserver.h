const char* FORMS = R""""(

<h1>Control your LEDs!</h1>

<h2>Choose a palette</h2>
<form action="/palette" method="POST">
    <input type="text" name="id">
    <input type="submit" value="Submit">
</form>

<h2>Choose a color</h2>
<form action="/color" method="POST">
    <input type="text" name="id">
    <input type="submit" value="Submit">
</form>

<h2>Choose the intensity</h2>
<form action="/intensity" method="POST">
    <input type="text" name="id">
    <input type="submit" value="Submit">
</form>

)"""";