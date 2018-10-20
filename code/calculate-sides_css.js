process = function () {
        var self = this;
        this.working = true;
        this.dom.next = $(this.dom.project[this.next]);
        this.dom.current.css('z-index', 30);
        self.dom.next.css('z-index', 20);
