<template>
  <div>
    <h1 data-aos="zoom-in">AOS Demo</h1>

    <div
      data-aos="zoom-out"
      data-aos-delay="500"
      data-aos-once="true"
      class="tabs four">
      <input
        v-for="(item, index) in img"
        v-bind:key="index"
        v-bind:id="'tab-' + index"
        v-bind:checked="!index ? true : false"
        name="tabGroup"
        type="radio">

      <div class="row">
        <div
          v-for="(item, index) in img"
          v-bind:key="index">
          <img v-bind:src="item">
        </div>
      </div>

      <label
        v-for="(item, index) in img"
        v-bind:key="index"
        v-bind:for="'tab-' + index">
        <img v-bind:src="item">
      </label>
    </div>

    <p
      data-aos="fade"
      data-aos-duration="1000">
      AOS is awesome! Thank you
      <a
        class="anchor"
        href="https://twitter.com/michalsnik">Michał Sajnóg</a>
      😄</p>

    <p
      data-aos="fade-up"
      data-aos-easing="ease">
      Paragraph with fade up animation and <code>ease</code> easing.</p>

    <p
      data-aos="fade-down"
      data-aos-anchor=".anchor">
      Paragraph with fade down animation with the above link as anchor. This makes this paragraph animate before the previous paragraph starts animating.</p>
  </div>
</template>

<script>
export default {
  data() {
    return {
      img: [
        "https://placeimg.com/800/450/animals",
        "https://placeimg.com/800/450/arch",
        "https://placeimg.com/800/450/nature",
        "https://placeimg.com/800/450/people"
      ]
    };
  }
};
</script>
